#include<iostream>
using namespace std;

class Rectangle{
private:
	int* lenght;
	int* width;
public:
	Rectangle(int, int);
	Rectangle(const Rectangle&);
	~Rectangle();
	void Print();
	const Rectangle& operator=(const Rectangle&);	
	void SetValues(int, int);
	bool IsEqual(Rectangle);
};

Rectangle::Rectangle(int l=0, int w=0)
{
	cout << "Constructor Called for l = "<<l<<" and w ="<<w<<".\n\n";
	lenght = new int(l);
	width = new int (w);
}
//// Comment this Copy Constructor and check behavior of Built-In Copy constructor
Rectangle::Rectangle(const Rectangle& rhsCC)
{
	cout<<"Copy Constructor Called to create a copy of Rectangle "<<*rhsCC.lenght<<" X "<<*rhsCC.width<<endl;
	cout<<"this:\t"<<this<<endl;
	cout<<"&resCC:\t"<<&rhsCC<<endl;
	lenght = new int( *rhsCC.lenght);
	width = new int ( *rhsCC.width);
}
Rectangle::~Rectangle()
{
	cout << "Destructor Called for rectangle "<<*lenght<<" X "<<*width<<"\n\n";
	if(lenght != 0) delete lenght;
	if(width != 0) delete width;
}
const Rectangle& Rectangle::operator=(const Rectangle& rhs)
{
	cout<<"Overloaded Assignment Operator Called for RHS "<<*rhs.lenght<<" X "<<*rhs.width<<endl;

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
bool Rectangle::IsEqual(Rectangle rhsIsEqual)
{
	cout<<"this:\t"<<this<<endl;
	cout<<"&resIsEqual:\t"<<&rhsIsEqual<<endl;

	if( (*lenght == *(rhsIsEqual.lenght)) && (*width == *(rhsIsEqual.width)))
	{
		cout<<"Both Rectangles are Equal.\n";		
		return true;
	}
	else
	{
		cout<<"Both Rectangles are NOT Equal.\n";
		return false;
	}
}
void main()
{	
	{
		Rectangle r1(2, 3);
		Rectangle r2(4, 5);

		cout<<"&r1:\t"<<&r1<<endl;
		cout<<"&r2:\t"<<&r2<<endl;

		cout << "\n\n\nGoing to pass an object by value to IsEqual function.\n\n";
		r1.IsEqual(r2);

		cout << "\n\n\nBack From IsEqual Function.\n";
			
		r2.SetValues(100, 200);
		cout << "r2:\t";
		r2.Print();
		cout << "\n\n\nObjects are going out of scope now. Everything will be destroyed now...\n\n\n";
		//Comment Copy Constructor and check what Built-in Copy Constructor does?
	}
	system("pause");
}