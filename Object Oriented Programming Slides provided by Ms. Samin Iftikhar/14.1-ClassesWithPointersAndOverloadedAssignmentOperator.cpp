#include<iostream>
using namespace std;

class Rectangle{
private:
	int* lenght;
	int* width;
public:
	Rectangle(int, int);
	~Rectangle();
	void Print();
	Rectangle& operator=(const Rectangle&);	//Overloaded Assignment Operator
	void SetValues(int, int);
};
Rectangle::Rectangle(int l = 0, int w = 0)
{
	cout << "\n\n\nConstructor Called with parameters " << l << " and " << w << "\n\n\n";
	lenght = new int(l);
	width = new int (w);
}
Rectangle::~Rectangle()
{
	cout << "Destructor Called for rectangle "<<*lenght<<" X "<<*width<<"\n\n";
	if(lenght != 0) delete lenght;
	if(width != 0) delete width;
}
/*
Class Notes
r2 = r1;
r2.operator=(r1)
Rectangle& Rectangle::operator=(const Rectangle& rhs)
{
	*lenght = *rhs.lenght;
	*width = *rhs.width;
	return *this;
}
*/
//comment Overloaded Assignment Operator and see the behavior of program.
Rectangle& Rectangle::operator=(const Rectangle& rhs)
{
	cout<<"Overloaded Assignment Operator Called for RHS "<<*rhs.lenght<<" X "<<*rhs.width<<endl;

	if( &rhs != this )	//Avoid self-assignment... r1 = r1
	{
		//De-allocate previous memory and allocate new memory (IF REQUIRED)
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
	int a=10, b=20, c=30;
	cout<<a<<"\t"<<b<<"\t"<<c<<endl;
	{
		Rectangle r1(2, 3);
		{
			cout << "Scope of r2 starting...\n\n";
			Rectangle r2;				
			cout << "r2 before Assignment:\t";
			r2.Print();
			//c1.add(c2);
			r2 = r1; //r2.operator=(r1);			
			
			cout << "r2 after Assignment:\t";
			r2.Print();
			
			cout << "r1 after Assignment:\t";
			r1.Print();

			//Cascading
			//a = b = c = 100;
			//cout<<a<<"\t"<<b<<"\t"<<c<<endl;

			Rectangle r3;
			r3 = r2 = r1; //r3.operator=(r2.operator=(r1));
			r3.Print();			
		}
		cout << "r2 went out of scope...\n\n";

		r1.SetValues(10,20);		
		cout << "r1:\t";
		r1.Print();
		cout << "\n\n\n r1 is going out of scope...\n\n\n";
		//Comment the overloaded Assignment Operator and see what built-in assignment operator does.
	}
	//cout << "Press any key to continue";
	//getchar();
}