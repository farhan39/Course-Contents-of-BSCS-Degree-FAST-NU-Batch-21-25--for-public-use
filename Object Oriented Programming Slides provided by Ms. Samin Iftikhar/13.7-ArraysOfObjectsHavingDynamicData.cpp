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
Rectangle::Rectangle(int l=0, int w=0)
{
	cout << "Overloaded Constructor Called with l = "<<l<<" and w = "<<w<<".\n\n";
	lenght = new int(l);
	width = new int(w);
}
Rectangle::~Rectangle()
{
	//What if we do not deallocate memory in destructor?
	cout << "Destructor Called for rectangle "<<*lenght<<"X"<<*width<<"\n";
	if(lenght != 0)
		delete lenght;	//Deallocated memory from heap
	if(width)
		delete width;	
}
void Rectangle::Print()
{
	//What will following line print now?
	//cout << "Rectangle is " << lenght << "X" << width<<endl<<endl;
	cout << *lenght << "X" << *width << endl << endl;
}
void Rectangle::SetValues(int l, int w)
{
	*lenght = l;
	*width = w;
}
void main()
{
	//int* arr1[5];
	Rectangle* array1[5];	//Array of 5 Rect* on Stack

	for(int i = 0 ; i< 5 ; i++)
		array1[i] = new Rectangle(i+1,i+1);

	for(int i = 0 ; i< 5 ; i++){
		cout<<"Rectangle["<<i<<"]\t";
		array1[i]->Print();
	}

	//what will delete[] array1 do???
	for(int i = 0 ; i< 5 ; i++)
		delete array1[i];
	//Are above pointers dangling? What should we do now?
	// array1[i] = 0; inside loop

	Rectangle** array2 = new Rectangle*[5];	//Array of 5 Rect* on heap

	for(int i = 0 ; i< 5 ; i++)
		array2[i] = new Rectangle(i+1,i+1);

	for(int i = 0 ; i< 5 ; i++){
		cout<<"Rectangle["<<i<<"]\t";
		array2[i]->Print();
	}

	for(int i = 0 ; i< 5 ; i++)
		delete array2[i];
	delete[] array2;

	//what if we miss for loop?
}