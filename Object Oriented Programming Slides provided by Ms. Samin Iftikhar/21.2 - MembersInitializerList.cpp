#include<iostream>
using namespace std;

class ComplexNumber
{
	int real;
	int imaginary;
public:
	void Output()
	{
		cout << real;
		if (imaginary >= 0)
			cout << "+";
		cout << imaginary << "i\n";
	}
	ComplexNumber(int r=0, int i=0): real(r), imaginary(i)
	{
		Output();
	}
};

void main()
{
	ComplexNumber c1(2,3);
}