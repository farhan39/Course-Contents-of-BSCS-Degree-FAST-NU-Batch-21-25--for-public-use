#include<iostream>
using namespace std;

class Rectangle{
private:
	int* lenght;
	int* width;
public:
	Rectangle(int, int);
	~Rectangle();
	void SetValues(int, int);
	void Print();
};
Rectangle::Rectangle(int l = 0, int w = 0)
{
	cout << "Overloaded Constructor Called with l = "<<l<<" and w = "<<w<<".\n\n";
	lenght = new int(l);	//Integer is on heap. Initializing integer to l
	width = new int(w);		//Initializing integer to w
}
Rectangle::~Rectangle()
{	
	cout << "Destructor Called for rectangle "<<*lenght<<"X"<<*width<<"\n";
	//What if we comment following lines
	if(lenght != 0)
		delete lenght;	//Deallocated memory from heap
	if(width)
		delete width;	
}
void Rectangle::Print()
{
	//What will following line print now?
	//cout << lenght << "X" << width<<endl<<endl;
	cout << *lenght << "X" << *width << endl << endl;
}
void Rectangle::SetValues(int l, int w)
{
	*lenght = l;
	*width = w;
}
//void main()
//{
//	//Create an object on heap
//	Rectangle *rectPtr1 = new Rectangle;
//	rectPtr1->Print();
//	rectPtr1->SetValues(3, 4);
//	rectPtr1->Print();
//
//	Rectangle *rectPtr2 = new Rectangle(10, 20);
//	rectPtr2->Print();
//
//	//what if we miss following lines?
//	delete rectPtr1;
//	delete rectPtr2;
//}