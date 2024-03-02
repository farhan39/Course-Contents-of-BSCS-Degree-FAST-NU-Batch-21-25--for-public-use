//#include<iostream>
//using namespace std;
//
//class Animal
//{
//private:
//	char name[20];
//public:
//	Animal(char*);
//	void Move();
//	char* GetName();
//};
//Animal::Animal(char* animalName = 0)
//{
//	if(animalName == 0)
//		strcpy_s(name, "Dummy");
//	else
//	{
//		strcpy_s(name, animalName);
//	}	
//}
//void Animal::Move()
//{
//	cout << name << " is MOVING.\n";
//}
//char* Animal::GetName()
//{
//	return name;
//}
//
//class Dog : public Animal
//{
//private:
//	char type[20];
//public:
//	Dog(char*, char*);
//	void Move();
//	//Child specific functionality
//	char* GetType()
//	{
//		return type;
//	}
//	void SetType(char* t)
//	{
//		strcpy_s(type,t);
//	}
//};
//Dog::Dog(char* dogName = 0, char* dogType = 0) : Animal(dogName)
//{
//	if(dogType == 0)
//		strcpy_s(type, "Simple");
//	else
//		strcpy_s(type, dogType);
//}
//void Dog::Move()
//{
//	cout << GetName() << " "<<type <<" is RUNNING.\n";
//}
//
//void main()
//{
//	Animal a1;
//	Dog* dPtr;
//
//	//Derived Class Pointer pointing to Base Class Object
//	dPtr = &(a1);
//	dPtr->Move();
//	
//	cout << endl << endl << endl;
//}