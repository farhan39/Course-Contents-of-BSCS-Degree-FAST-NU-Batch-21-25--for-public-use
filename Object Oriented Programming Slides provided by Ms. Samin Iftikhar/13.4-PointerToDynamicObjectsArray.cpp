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
	cout << "Overloaded Constructor Called with l = "<<l<<" and w = "<<w<<".\n\n";
	lenght = l;
	width = w;
}
Rectangle::~Rectangle()
{
	cout << "Destructor Called for rectangle "<<lenght<<"X"<<width<<"\n";
}
void Rectangle::Print()
{
	cout << lenght << "X" << width<<endl<<endl;
}
void Rectangle::SetValues(int l, int w)
{
	lenght = l;
	width = w;
}
//void main()
//{
//	//What is difference between Test1 and Test2?
//
//	//Test 1
//	//----------------------------------------------
//	//int* abc = new int[5];
//	Rectangle* rPtr = new Rectangle[5];	//Array of 5 Rectangles on Heap
//
//	for (int i = 0; i < 5; i++)
//		rPtr[i].SetValues(i+1, i+1);
//
//	for (int i = 0; i < 5; i++){
//		cout<<"Rectangle["<<i<<"]\t";
//		rPtr[i].Print();
//	}
//
//	//Comment this line and see what happens?
//	if(rPtr){
//	delete[] rPtr;
//	rPtr = 0;
//	}
//
//	//----------------------------------------------
//	
//
//	//Test 2
//	//----------------------------------------------
//	Rectangle rPtr2[5]; //Array of 5 Rectangles on Stack
//
//	for (int i = 0; i < 5; i++)
//		rPtr2[i].SetValues(i+1, i+1);
//
//	for (int i = 0; i < 5; i++){
//		cout<<"Rectangle["<<i<<"]\t";
//		rPtr2[i].Print();
//	}
//
//	//delete[] rPtr; Do we need this?
//	//----------------------------------------------
//
//}