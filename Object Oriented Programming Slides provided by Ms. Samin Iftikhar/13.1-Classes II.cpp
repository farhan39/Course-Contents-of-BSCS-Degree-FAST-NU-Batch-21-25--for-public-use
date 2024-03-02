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

Rectangle::Rectangle(int l=0, int w=0)
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
//	Rectangle r1;
//	Rectangle r2(2, 3);
//}