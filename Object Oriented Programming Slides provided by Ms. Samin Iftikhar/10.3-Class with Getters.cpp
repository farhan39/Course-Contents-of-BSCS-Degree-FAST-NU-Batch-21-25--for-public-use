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
	void SetLenght(int);
	void SetWidth(int);
	
	//Getters
	int GetLenght();
	int GetWidth();
	
	~Rectangle();
};

int Rectangle::GetLenght()
{
	return lenght; //this->lenght;
}

int Rectangle::GetWidth()
{
	return width;
}

void Rectangle::SetLenght(int l)
{
	lenght = l;
}

void Rectangle::SetWidth(int w)
{
	width = w;
}

int Rectangle::Area()
{
	return lenght*width;
}

Rectangle::~Rectangle()
{
	cout << "\nDestructor Called.\n";
}

Rectangle::Rectangle(int l=0, int w=0)
{
	cout << "\nOverloaded Constructor Called with parameters " << l << " and " << w << "\n";
	lenght = l;
	width = w;
}

void Rectangle::Print()
{
	cout << lenght << " X " <<width<<endl;
}

void main()
{
	Rectangle r1;
	cout << "Rectangle 1:\n";
	r1.Print();

	Rectangle r2(5, 10);
	cout << "Rectangle 2:\n";
	r2.Print();

	cout << "Reading Rectangle 2's data in Main():\n";
	cout << r2.GetLenght() << "\t" << r2.GetWidth() << endl << endl;

}