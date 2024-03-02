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
//Comment the code given below and see what happens
Rectangle::~Rectangle()
{	
	//What if we do not deallocate memory in destructor?
	cout << "Destructor Called for rectangle ";
	Print();
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
	*lenght = l;	//*((*this).len) = l
	*width = w;
}
void main()
{
	//Create an object on stack
	Rectangle r1(5,10);
	r1.Print();
	
	Rectangle r2;
	r2.SetValues(3,4);
	r2.Print();
}