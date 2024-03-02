#include<iostream>
using namespace std;

class MyList
{
private:
	int size;
	int* myArray;
	int currIndex;

public:
	MyList(int);
	~MyList();
	void AddElement(int); 
	void PrintAll(){
		for(int i=0; i<size ; i++)
			cout<<myArray[i]<<endl;
	}
};

MyList::MyList(int s = 10)
{
	size = s;
	currIndex = 0;

	if (size > 0)
		myArray = new int[size];
	else
		myArray = 0;
}

MyList::~MyList()
{
	if (myArray)
		delete[] myArray;
}

void MyList::AddElement(int element)
{
	if (currIndex == size)
	{
		int* newArray = new int[size*2];
		for(int i=0; i<size ; i++)
			newArray[i] = myArray[i];
		size = size * 2;
		delete[] myArray;
		myArray = newArray;
	}
	myArray[currIndex] = element;
	currIndex++;	
}

void main()
{
	MyList intList(3);

	intList.AddElement(5);
	intList.AddElement(10);
	intList.AddElement(15);
	intList.AddElement(20);

	intList.PrintAll();	
}