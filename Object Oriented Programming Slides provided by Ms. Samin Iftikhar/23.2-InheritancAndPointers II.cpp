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
//	cout << type <<" "<< GetName() <<" is RUNNING.\n";
//}
//
//void main()
//{
//	Animal* aPtr;
//	Dog d1("Tommy","BullDog");
//
//	//Base Class Pointer pointing to Derived Class Object
//
//	aPtr = &d1;
//	aPtr->Move();	//Data of derived class, Function of base class
//	
//	cout << endl << endl << endl;
//}