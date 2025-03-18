#include<initializer_list>
using namespace std;
class Sort
{
    int n;
    int* a;
public:
    Sort(int nr, int m, int M);
    Sort(initializer_list<int>v);
    Sort(const int* v, int k);
    Sort(const char* s);
    Sort(int nr, ...);
    void InsertSort(bool ascendent);
    void QuickSort(bool ascendent);
    void BubbleSort(bool ascendent);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

