#include<iostream>
using namespace std;

class Rectangle{
private:
	int* lenght;
	int* width;
public:
	Rectangle(int, int);
	Rectangle(const Rectangle&);	//Copy Constructor
	~Rectangle();
	void Print();
	const Rectangle& operator=(const Rectangle&);	
	void SetValues(int, int);
};

Rectangle::Rectangle(int l=0, int w=0)
{
	cout << "Constructor Called for l = "<<l<<" and w ="<<w<<".\n\n";
	lenght = new int(l);
	width = new int (w);
}
/*
Class Notes
//Rectangle r2(r1);
//Rectangle r2=r1;
Rectangle::Rectangle(const Rectangle& rhs)
{
	lenght = new int(*rhs.lenght);
	width = new int(*rhs.width);
}
*/
//Rectangle::Rectangle(Rectangle rhs) ... what is this???
// Comment this Copy Constructor and check behavior of Built-In Copy constructor
Rectangle::Rectangle(const Rectangle& rhs)
{
	cout<<"Copy Constructor Called to create a copy of Rectangle "<<*rhs.lenght<<" X "<<*rhs.width<<endl;
	lenght = new int( *rhs.lenght);
	width = new int ( *rhs.width);
}
Rectangle::~Rectangle()
{
	cout << "Destructor Called for rectangle "<<*lenght<<" X "<<*width<<"\n\n";
	if(lenght != 0) delete lenght;
	if(width != 0) delete width;
}
const Rectangle& Rectangle::operator=(const Rectangle& rhs)
{
	cout<<"Overloaded Assignment Operator Called for LHS "<<*rhs.lenght<<" X "<<*rhs.width<<endl;

	if( &rhs != this )	//Avoid self-assignment
	{
		//De-allocate previous memory and allocate new memory IF REQUIRED
		*lenght = *rhs.lenght;
		*width = *rhs.width;
	}
	return *this;
}
void Rectangle::Print()
{
	cout << *lenght << " X " << *width<<endl<<endl;
}
void Rectangle::SetValues(int l , int w)
{
	*lenght = l;
	*width = w;
}
void main()
{
	{
		Rectangle r1(2, 3);
		{
			Rectangle r2 = r1;		//Will this call assignment operator or copy constructor?
			//Rectangle r2(r1);		//Both these lines are doing same thing. Uncomment one at a time and check
			cout << "r1:\t";
			r1.Print();
			cout << "r2:\t";
			r2.Print();
		}		
		r1.SetValues(20, 30);
		cout << "r1:\t";
		r1.Print();		
		cout << "\n\n\n r1 is going out of scope...\n\n\n";
		//Comment the Copy Constructor and see what built-in copy constructor does.
	}
	cout << "Press any key to continue";
	getchar();
}