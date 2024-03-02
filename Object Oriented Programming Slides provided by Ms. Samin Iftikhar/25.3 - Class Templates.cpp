#include<iostream>
using namespace std;

class Dog
{
	friend ostream& operator<<(ostream& out, Dog& d);
private:
	char name[20];
public:
	Dog();
	Dog(char*);	
	char* GetName(){ return name; }
};
Dog::Dog()
{
	strcpy_s(name, "Tommy");
}
Dog::Dog(char* n)
{
	strcpy_s(name, n);
}

ostream& operator<<(ostream& out, Dog& d)
{
	cout<<d.GetName()<<endl;
	return out;
}
template<class T>
class MyList
{
private:
	int size;
	T* myArray;
	int currIndex;

public:
	MyList(int);
	~MyList();
	void AddElement(T); 
	void PrintAll(){
		for(int i=0; i<size ; i++)
			cout<<myArray[i]<<endl;
	}
};

template<class T>	//Template 
MyList<T>::MyList(int s = 10)
{
	size = s;
	currIndex = 0;

	if (size > 0)
		myArray = new T[size];
	else
		myArray = 0;
}
template<class T>
MyList<T>::~MyList()
{
	if (myArray)
		delete[] myArray;
}

template<class T>
void MyList<T>::AddElement(T element)
{
	if (currIndex == size)
	{
		T* newArray = new T[size*2];
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
	MyList<int> intList(3);

	intList.AddElement(5);
	intList.AddElement(10);
	intList.AddElement(15);
	intList.AddElement(20);

	intList.PrintAll();

	cout<<endl<<endl;

	MyList<float> floatList(3);

	floatList.AddElement(5.5);
	floatList.AddElement(10.5);
	floatList.AddElement(15.4);
	floatList.AddElement(20.3);

	floatList.PrintAll();

	cout<<endl<<endl;

	MyList<Dog> dogsList(3);

	
	dogsList.AddElement(Dog("tony"));
	dogsList.AddElement(Dog("jojo"));
	dogsList.AddElement(Dog("dolly"));
	dogsList.AddElement(Dog("Scooby Doo"));
	
	dogsList.PrintAll();
}