#include<iostream>
using namespace std;

int* GetArray()
{
	int size = 10;
	int* aPtr = new int[size];
	cout<<"\n\n\nInitialize and Print Array:\n";
	for(int i = 0 ; i < size ; i++)
	{
		aPtr[i] = i+1;
		cout<<aPtr[i]<<endl;
	}
	delete[] aPtr;
	return aPtr;
}
int* GetArray2()
{
	int* temp = new int[5];
	for(int i = 0 ; i < 5 ; i++)
	{
		temp[i] = i+1;
		cout<<temp[i]<<endl;
	}
	return temp;
}
void main()
{
	//// Activity 1:
	//int* myArray = GetArray();		//What went wrong in this function. Fix this issue.
	//cout << "I am back in main()" << endl;
	//cout<<"\n\n\nmyArray[0]:\t"<<myArray[0]<<endl;	

	// Activity 2:
	int* myArray2 = new int[1];	//This should be initialized to 0.
	myArray2 = GetArray2();		//What went wrong in this function. Fix this issue.
	cout << "I am back in main()" << endl;
	cout<<"\n\n\nmyArray2[0]:\t"<<myArray2[0]<<endl;	

}