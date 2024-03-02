#include<iostream>
using namespace std;

class ComplexNumber
{
private:
	int real;
	int imaginary;
public:	
	ComplexNumber(int, int);
	void Print();
	ComplexNumber operator+(const ComplexNumber&);
};

ComplexNumber::ComplexNumber( int r = 0, int i = 0)
{
	real = r;
	imaginary = i;
}
void ComplexNumber::Print()
{
	cout << real;
	if (imaginary >= 0)
		cout << "+";
	cout << imaginary <<"i";
}
ComplexNumber ComplexNumber::operator+(const ComplexNumber& rhs)
{
	// Uncomment following lines of code to check associativity
	// remove the keyword const from prototype in order to run these lines.
	//Print();
	//cout << "+";
	//rhs.Print();	
	//cout << endl;

	ComplexNumber result(real+rhs.real, imaginary+rhs.imaginary);
	return result;
}
void main()
{
	ComplexNumber c1(3,4);
	ComplexNumber c2(2, 2);
	ComplexNumber c3(3, 1);

	int i = 10;
	int j = 20;

	int k = i+j;


	ComplexNumber c4 = c1 + c2;			// c1.operator+(c2);
	//ComplexNumber c4 = c1 + c2 + c3;	//This is cascaded statement (order of evaluation: left to right)
	cout << "c4 = ";
	c4.Print();
	cout << endl;

}