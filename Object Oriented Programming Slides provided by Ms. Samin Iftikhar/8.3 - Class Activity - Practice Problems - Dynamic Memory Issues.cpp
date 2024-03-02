//Common Issues in Assignments
#include<iostream>
using namespace std;

int* GetArrayFromUser(int& _size)
{
	cout<<"Enter size of Array:\t";
	cin>>_size;
	int* tempArray = 0;
	if(_size > 0)
	{
		tempArray = new int[_size];
		for(int i = 0; i< _size ; i++)
			tempArray[i] = i+1;
	}
	//delete[] tempArray; //Activity 3 - Uncomment this line and check behavior
	return tempArray;
}

void UpdateArray(int* intArray, const int& _size)
{
	for(int i = 0; i< _size ; i++)
			intArray[i] = intArray[i] * 2;
	//delete[] intArray //Activity 4 - Uncomment this line and check behavior
}

void DisplayArray(int* tempArray, const int& _size)
{
	cout<<"\n\n\nData in Array:"<<endl;
	for(int i = 0; i< _size ; i++)
	{
			cout<<"tempArray["<<i<<"]\t"<<tempArray[i]<<endl;
	}
}

void main()
{
	//Activity (a)
	int size = 2;
	int* myArray = 0;// = new int[size]; //Activity 1 - uncomment this line.

	myArray = GetArrayFromUser(size);
	//myArray = new int[size];	//Comment this for Activity 3
	if (myArray != 0)		//Activity 2 - Comment this line and give size less than 1. What will be the behavior?
	{
		UpdateArray(myArray, size);
		DisplayArray(myArray, size);		
		delete[] myArray;
	}

	//Activity (b)
	int* arr[3];
	for(int i=0; i<3 ; i++)
		arr[i] = new int[5];

	//How to deallocate memory now?
}