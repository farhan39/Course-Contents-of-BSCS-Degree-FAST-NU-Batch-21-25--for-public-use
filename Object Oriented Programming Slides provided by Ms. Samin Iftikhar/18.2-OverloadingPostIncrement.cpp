#include<iostream>
using namespace std;

class ComplexNumber
{
	friend ostream& operator<<(ostream&, const ComplexNumber&);
	friend istream& operator>>(istream&, ComplexNumber&);
private:
	int real;
	int imaginary;
public:
	ComplexNumber();
	ComplexNumber(int, int);	
	ComplexNumber operator+(const ComplexNumber&);
	ComplexNumber operator++(int);					// PostIncrement
};

ComplexNumber::ComplexNumber()
{
	real = imaginary = 0;
}
ComplexNumber::ComplexNumber( int r, int i)
{
	real = r;
	imaginary = i;
}




//Overloaded PostIncrement with dummy integer parameter without parameter name
ComplexNumber ComplexNumber::operator++()
{	
	ComplexNumber temp = *this;	//Hold current state of object
	//ComplexNumber temp (*this);	//This line is working same as above

	real++;
	//return unincremented, saved, temporary object
	return temp;	//return by value.Why not by reference?
}



ComplexNumber ComplexNumber::operator+(const ComplexNumber& rhs)
{
	// Uncomment following lines of code to check associativity
	// remove the keyword const from prototype in order to run these lines.
	Print();
	cout << "+";
	rhs.Print();	
	cout << endl;

	ComplexNumber result;
	result.real = real + rhs.real;
	result.imaginary = imaginary + rhs.imaginary;
	return result;
}
//overloaded stream insertion operator
ostream& operator<<(ostream& out, const ComplexNumber& obj)
{
	out << obj.real;
	if (obj.imaginary >= 0)
		out << "+";
	out << obj.imaginary << "i";
	return out;	// to enable cascading
}

//overloaded stream extraction operator
istream& operator>>(istream& in, ComplexNumber& obj)
{
	in >> obj.real;
	in >> obj.imaginary;
	return in;	// to enable cascading
}
void main()
{
	ComplexNumber c1(3,4);
	ComplexNumber c2(2, 2);
	ComplexNumber c3(3, 1);

	cout << "c1 = " << c1 << endl;
	int i = 10;
	cout << "i++ = " << i++ << endl;
	cout << "i = " << i << endl;
	cout << "c1++ = " << c1++ << endl;	//c1.operator++(0), Argument 0 is dummy value to distinguish between pre and post increment.
	//Increment the object but print previous value.
	cout << "c1 = " << c1 << endl;
	cout << endl << endl << endl;
	cout << "c2 = " << c2 << endl;
	cout << "c3 = " << c3 << endl;
	ComplexNumber c4 = c2++ + c3;
	cout << "c4 = c2++ + c3 :\t" << c4 << endl;
	cout << "c2 = " << c2 << endl;
}