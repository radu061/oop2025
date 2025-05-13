#include<exception>
#include<iostream>
using namespace std;
class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
class exceptie2 : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Indexul este inafara domeniului!";
    }
};
class exceptie3 : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Nu exista destul loc in lista!";
    }
};
template<class T>
class ArrayIterator
{
private:
    int Current;
    int size;
    T** array;
    // mai adaugati si alte date si functii necesare pentru iterator
public:
    ArrayIterator()
    {
        this->Current = 0;
        this->size = 0;
    }
    ArrayIterator(int c, int s, T** arr)
    {
        this->Current = c;
        this->size = s;
        this->array = arr;
    }
    ArrayIterator& operator ++ ()
    {
        this->Current++;
        return *this;
    }
    ArrayIterator& operator -- ()
    {
        this->Current--;
        return *this;
    }
    bool operator= (ArrayIterator<T>& other)
    {
        return this->Current == other.Current;
    }
    bool operator!=(ArrayIterator<T>& other)
    {
        return this->Current != other.Current;
    }
    T* GetElement()
    {
        return this->array[this->Current];
    }
};
template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() // Lista nu e alocata, Capacity si Size = 0
    {
        this->Capacity = this->Size = 0;
        this->List = nullptr;
    }
    ~Array()// destructor
    {
        delete[] this->List;
        this->Size = this->Capacity = 0;
    }
    Array(int capacity) // Lista e alocata cu 'capacity' elemente
    {
        this->List = new T*[capacity];
        this->Capacity = capacity;
        this->Size = 0;
        for (int i = 0;i < this->Capacity;i++)
            this->List[i] = nullptr;
    }
    Array(const Array<T>& otherArray) // constructor de copiere
    {
        for (int i = 0;i < this->Capacity;i++)
            this->List[i] = nullptr;
        delete[] this->List;
        this->Capacity = otherArray.Capacity;
        this->Size = otherArray.Size;
        this->List = new T*[this->Capacity];
        for (int i = 0;i < this->Capacity;i++)
            this->List[i] = new T(*otherArray.List[i]);
    }

    T& operator[] (int index) // arunca exceptie daca index este out of range
    {
        exceptie2 indexoutofrange;
        try
        {
            if (index < 0 || index >= this->Capacity)
                throw indexoutofrange;
            return *this->List[index];
        }
        catch (exceptie2& e)
        {
            cout << "Exceptie: " << e.what() << endl;
        }
    }

    const Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
    {
        exceptie3 preaputinspatiu;
        try
        {
            if (this->Size >= this->Capacity)
                throw preaputinspatiu;

            this->List[this->Size++] = new T(newElem);
            return *this;
        }
        catch (exceptie3 e)
        {
            cout << "Exceptie: " << e.what() << '\n';
        }
    }
    const Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        exceptie2 indexoutofrange;
        exceptie3 preaputinspatiu;
        try
        {
            if (index < 0 || index >= this->Capacity)
                throw indexoutofrange;
            if (this->Size >= this->Capacity)
                throw preaputinspatiu;
            this->List[this->Size] = new T(*this->List[this->Size - 1]);
            this->Size++;
            for (int i = this->Size - 1;i > index;i--)
                this->List[i] = this->List[i-1];
            this->List[index + 1] = new T(*this->List[index + 1]);
            delete this->List[index];
            this->List[index] = new T(newElem);
        }
        catch (exceptie2& e)
        {
            cout << "Exceptie: " << e.what() << endl;
        }
        catch (exceptie3 e)
        {
            cout << "Exceptie: " << e.what() << '\n';
        }
    }
    const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        exceptie2 indexoutofrange;
        exceptie3 preaputinspatiu;
        try
        {
            if (index < 0 || index >= this->Capacity)
                throw indexoutofrange;
            if (this->Size+otherArray.Size > this->Capacity)
                throw preaputinspatiu;
            for (int i = 0;i < otherArray.Size;i++)
                this->Insert(index + i, otherArray.List[i]);
            this->Size += otherArray.Size;
        }
        catch (exceptie2& e)
        {
            cout << "Exceptie: " << e.what() << endl;
        }
        catch (exceptie3 &e)
        {
            cout << "Exceptie: " << e.what() << '\n';
        }
    }
    const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    {
        exceptie2 indexoutofrange;
        try
        {
            if (index < 0 || index >= this->Capacity)
                throw indexoutofrange;
            for (int i = index;i < this->Size - 1;i++)
                this->List[i] = this->List[i + 1];
            this->Size--;
        }
        catch (exceptie2& e)
        {
            cout << "Exceptie: " << e.what() << endl;
        }
    }
    bool operator==(const Array<T>& otherArray)
    {
        if (this->Size != otherArray.Size)return 0;
        for (int i = 0;i < this->Size;i++)
            if (this->List[i] != otherArray[i])
                return 0;
        return 1;
    }

    void Sort() // sorteaza folosind comparatia intre elementele din T
    {
        bool ok = 0;
        while (!ok)
        {
            ok = 1;
            for (int i = 0;i < this->Size-1;i++)
                if (*this->List[i] > *this->List[i + 1])
                {
                    ok = 0;
                    swap(this->List[i], this->List[i + 1]);
                }
        }
    }
    void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
    {
        bool ok = 0;
        while (!ok)
        {
            ok = 1;
            for (int i = 0;i < this->Size-1;i++)
                if (compare(*this->List[i] , *this->List[i + 1])>0)
                {
                    ok = 0;
                    swap(this->List[i], this->List[i + 1]);
                }
        }
    }
    void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
    {
        bool ok = 0;
        while (!ok)
        {
            ok = 1;
            for (int i = 0;i < this->Size-1;i++)
                if (comparator->CompareElements(this->List[i],this->List[i+1])>0)
                {
                    ok = 0;
                    swap(this->List[i], this->List[i + 1]);
                }
        }
    }
    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
    {
        this->Sort();
        int st = 0, dr = this->Size - 1;
        while (st < dr)
        {
            int mij = (st + dr) / 2;
            if (*this->List[mij] == elem)
                return mij;
            else if (*this->List[mij] > elem)
                dr = mij - 1;
            else st = mij + 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
    {
        this->Sort();
        int st = 0, dr = this->Size - 1;
        while (st < dr)
        {
            int mij = (st + dr) / 2;
            int rez = compare(this->List[mij], elem);
            if (rez==0)
                return mij;
            else if (rez>0)
                dr = mij - 1;
            else st = mij + 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator
    {
        this->Sort();
        int st = 0, dr = this->Size - 1;
        while (st < dr)
        {
            int mij = (st + dr) / 2;

            int rez = comparator->CompareElements((void*)this->List[mij],(void*) &elem);
            if (rez == 0)
                return mij;
            else if (rez > 0)
                dr = mij - 1;
            else st = mij + 1;
        }
        return -1;
    }
    int Find(const T& elem) // cauta un element in Array
    {
        for (int i = 0;i < this->Size;i++)
            if (*this->List[i] == elem)
                return i;
        return -1;
    }
    int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
    {
        for (int i = 0;i < this->Size;i++)
            if (compare(*this->List[i],elem)==0)
                return i;
        return -1;
    }
    int Find(const T& elem, Compare* comparator)//  cauta un element folosind un comparator
    {
        for (int i = 0;i < this->Size;i++)
            if (comparator->CompareElements(this->List[i], elem) == 0)
                return i;
        return -1;
    }
    int GetSize() { return this->Size; }
    int GetCapacity() { return this->Capacity; }

    ArrayIterator<T> GetBeginIterator()
    {
        ArrayIterator<T>it(0,this->Size,this->List);
        return it;
    }
    ArrayIterator<T> GetEndIterator()
    {
        ArrayIterator<T>it(this->Size, this->Size, this->List);
        return it;
    }
};
