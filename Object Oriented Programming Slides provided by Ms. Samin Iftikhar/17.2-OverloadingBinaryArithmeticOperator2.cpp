#include<iostream>
using namespace std;

class ComplexNumber
{
private:
	int real;
	int imaginary;
public:
	ComplexNumber();
	ComplexNumber(int, int);
	void Print();
	ComplexNumber operator+(const int&);
};

ComplexNumber::ComplexNumber()
{
	real = imaginary = 0;
}
ComplexNumber::ComplexNumber(int r, int i)
{
	real = r;
	imaginary = i;
}
void ComplexNumber::Print()
{
	cout << real;
	if (imaginary >= 0)
		cout << "+";
	cout << imaginary << "i";
}
ComplexNumber ComplexNumber::operator+(const int& i)
{
	ComplexNumber result(real+i, imaginary);
	return result;
}
void main()
{
	ComplexNumber c1(3, 4);	

	ComplexNumber c4 = c1 + 2;	// c1.operator+(2)
	cout << "c4 = ";
	c4.Print();
	cout << endl;

}