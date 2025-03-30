class Number
{
	int base;
	char* nr;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int n);
	~Number();
	Number(const Number& n);
	Number(Number&& n);
	// add operators and copy/move constructor
	friend Number operator +(const Number& n1, const Number& n2);
	friend Number operator -(const Number& n1, const Number& n2);
	friend bool operator >(const Number& n1, const Number& n2);
	friend bool operator <(const Number& n1, const Number& n2);
	friend bool operator <=(const Number& n1, const Number& n2);
	friend bool operator >=(const Number& n1, const Number& n2);
	friend bool operator ==(const Number& n1, const Number& n2);
	friend bool operator !=(const Number& n1, const Number& n2);
	void operator +=(const Number& n);
	void operator -=(const Number& n);
	char operator[](const int index);
	void operator --(int val);
	void operator --();
	Number& operator = (const Number& n);
	Number& operator = (int n);
	Number& operator = (const char *n);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};