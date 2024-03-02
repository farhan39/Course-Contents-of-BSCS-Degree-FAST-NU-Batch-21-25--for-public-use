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
	void Input();
	int GetLenght();
	int GetWidth();
	int Compare(Rectangle);
	Rectangle GetRotatedRectangle();
	~Rectangle();
};

Rectangle::Rectangle(int l=0, int w=0)
{
	cout << "\nConstructor Called with parameters " << l << " and " << w << "\n";
	lenght = l;
	width = w;
}

Rectangle Rectangle::GetRotatedRectangle()
{
	//WE DO NOT NEED GETTERS/SETTERS TO READ/WRITE PRIVATE DATA HERE
	//Private data is directly accessible in this scope
	Rectangle temp;
	temp.lenght = width;	//temp.lenght = this->width;
	temp.width = lenght;

	//OR
	//Rectangle temp(width, lenght);

	return temp;
}

int Rectangle::Compare(Rectangle rhs)
{
	int areaLhs = Area();
	int areaRhs = rhs.Area();

	if (areaLhs < areaRhs)
	{
		cout << "Left Hand Side Rectangle is Smaller than RHS Rectangle.\n";
		return -1;
	}
	else if (areaLhs > areaRhs)
	{
		cout << "Left Hand Side Rectangle is Larger than RHS Rectangle.\n";
		return 1;
	}
	else
	{
		cout << "Left Hand Side Rectangle is Equal to RHS Rectangle.\n";
		return 0;
	}
}

void Rectangle::Input()
{
	cout << "Enter Lenght:\t";
	cin >> lenght;
	cout << "Enter Width:\t";
	cin >> width;
}

int Rectangle::GetLenght()
{
	return lenght;
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
	cout << "\nDestructor Called for Rectangle " << lenght << "X" << width << endl;
}

void Rectangle::Print()
{
	cout << lenght << " X " << width << endl;
}

void main()
{
	Rectangle r1(5, 10);
	cout << "Rectangle 1:\t";
	r1.Print();

	Rectangle r2(2,3);
	cout << "Rectangle 2:\t";
	r2.Print();

	cout<<"Calling Get Rotated Rect.\n";
	r2 = r1.GetRotatedRectangle();

	cout << "Rectangle 2:\t";
	r2.Print();	
	system("pause");
}