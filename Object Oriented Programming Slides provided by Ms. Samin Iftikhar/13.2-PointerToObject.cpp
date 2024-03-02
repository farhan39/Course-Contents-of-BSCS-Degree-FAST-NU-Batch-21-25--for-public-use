#include<iostream>
using namespace std;

class Rectangle{
private:
	int lenght;
	int width;
public:
	Rectangle(int, int);
	~Rectangle();
	void SetValues(int, int);
	void Print();
};
Rectangle::Rectangle(int l = 0, int w = 0)
{
	cout << "Overloaded Constructor Called with l = " << l << " and w = " << w << ".\n\n";
	lenght = l;
	width = w;
}
Rectangle::~Rectangle()
{
	cout << "Destructor Called for rectangle ";
	Print();
}
void Rectangle::Print()
{
	cout << lenght << "X" << width << endl;
}
void Rectangle::SetValues(int l, int w)
{
	lenght = l;
	width = w;
}
//void main()
//{	
//	Rectangle* rectPtr;
//	Rectangle r1(3,4);
//
//	rectPtr = &r1; //rectPtr is pointing to r1
//	rectPtr->Print();
//
//	cout << "rectPtr = " << rectPtr << endl;
//	cout << "Size of rectPtr = " << sizeof(rectPtr) << endl;
//	cout << "Function is terminating. Everything will be disposed now...\n\n";
//}