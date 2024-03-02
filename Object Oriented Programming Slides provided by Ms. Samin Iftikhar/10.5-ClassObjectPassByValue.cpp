#include<iostream>
using namespace std;

class Rectangle
{
private:
	int lenght;
	int width;

public:
	Rectangle(int, int);
	void Print();
	int Area();	
	void Input();	
	int Compare(Rectangle);
	~Rectangle();
};

int Rectangle::Compare(Rectangle rhs)	//Rectangle Pass by Value
{
	int areaLhs = Area();	//Area of this object, for which the function has been called (Left hand side object)
	int areaRhs = rhs.Area();	//Area of the object which has been passed as parameter (Right hand side object)

	//Check addresses
	cout <<"this:\t" <<this << endl;
	cout <<"&rhs:\t" <<&rhs << endl;

	//changing parameter here
	rhs.lenght = rhs.lenght * 100;
	if (areaLhs < areaRhs)
	{
		cout << "LHS < RHS.\n";
		return -1;
	}
	else if (areaLhs > areaRhs)
	{
		cout << "LHS > RHS.\n";
		return 1;
	}
	else
	{
		cout << "LHS = RHS.\n";
		return 0;
	}
}

int Rectangle::Area()
{
	return lenght*width;
}

Rectangle::~Rectangle()
{
	cout << "\nDestructor Called for Rectangle " << lenght << "X" << width << endl;
}

Rectangle::Rectangle(int l=0, int w=0)
{
	cout << "\nConstructor Called with parameters " << l << " and " << w << "\n";
	lenght = l;
	width = w;
}

void Rectangle::Print()
{	
	cout << lenght << " X " << width << endl;
}

void main()
{
	Rectangle r1;
	Rectangle r2(5, 10);
	
	cout << "Rectangle 1:\t";
	r1.Print();
		
	cout << "Rectangle 2:\t";
	r2.Print();

	cout << "Address of r1:\t" << &r1 << endl;
	cout << "Address of r2:\t" << &r2 << endl;

	cout << "Going to Call r1.Compare(r2)\n\n";
	r1.Compare(r2);	

	//Check if r2 changed in Compare function
	cout << "Rectangle 2 after function call:\t";
	r2.Print();

}