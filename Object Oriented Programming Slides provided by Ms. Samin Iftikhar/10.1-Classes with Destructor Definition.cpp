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
	~Rectangle();	//Class can have only one destructor, without any parameters. Note the name and return type of destructor (~ Tilde Sign)
};
//Destructor's Properties:
// 1- No Parameters
// 2- No Return Type
// 3- Implicit Call ONLY

Rectangle::Rectangle(int l = 0, int w = 0)
{
	cout << "\nConstructor Called with parameters " << l << " and " << w << "\n";
	lenght = l;
	width = w;
}
Rectangle::~Rectangle()
{
	cout << "\nDestructor Called for Rectangle:\t";
	Print(); //this->Print();
}
void Rectangle::Print()
{
	cout << lenght << " X " << width << endl;
}

void main()
{
	Rectangle r1;
	cout<<"Rectangle r1:\n";
	r1.Print();

	{ 
		Rectangle r2(5,10);
		cout<<"Rectangle r2:\n";
		r2.Print();
	}

	Rectangle r3(100,200);
	cout<<"Rectangle r3:\n";
	r3.Print();	
}