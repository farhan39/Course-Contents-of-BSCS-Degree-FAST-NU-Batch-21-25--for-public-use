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
	
	//Setters
	void SetLenght(int);
	void SetWidth(int);
	
	~Rectangle();
};

void Rectangle::SetLenght(int l)
{
	lenght = l;	//this->lenght = l;
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
	cout << "\nDestructor Called for Rectangle " << lenght << " X " << width << endl;
}

Rectangle::Rectangle(int l = 0, int w=0)
{
	cout << "\nOverloaded Constructor Called with parameters " << l << " and " << w << "\n";
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
	cout << "Rectangle 1:\t";
	r1.Print();

	Rectangle r2(5, 10);
	cout << "Rectangle 2:\t";
	r2.Print();

	cout << "Area of Rectangle 1:\t" << r1.Area() << endl << endl;
	cout << "Area of Rectangle 2:\t" << r2.Area() << endl << endl;

	//UNCOMMENT FOLLOWING TWO LINES TO CHANGE VALUES IN R1
	//r1.lenght = 2;
	//r1.width = 3;
	//WHY CAN'T WE MODIFY RECTANGLE'S DATA HERE?
	//BECAUSE THESE ARE PRIVATE MEMBERS OF CLASS

	r1.SetLenght(2);
	r1.SetWidth(3);
	
	cout << "Print Updated Rectangle 1:\t";
	r1.Print();
	cout << "Area of Rectangle 1:\t" << r1.Area() << endl << endl;
	
}