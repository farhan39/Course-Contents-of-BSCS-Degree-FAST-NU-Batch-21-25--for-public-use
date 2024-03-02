#include<iostream>
using namespace std;

class Animal
{
private:
	char name[30];
public:
	Animal(char*);
	virtual void Move();
	char* GetName();
	virtual ~Animal();		//Note this prototype
};
Animal::Animal(char* animalName = 0)
{
	if(animalName == 0)
		strcpy_s(name, "Dummy");
	else
	{
		strcpy_s(name, animalName);
	}	
}
void CommonFunctionality()
{
	cout<<"abc"<<endl;
}
void Animal::Move()
{
	cout << name << " is MOVING.\n";
}
char* Animal::GetName()
{
	return name;
}
Animal::~Animal()
{
	cout << "~Animal() called.\n";
}
//----------------------------------------------------------------
class Dog : public Animal
{
private:
	char type[20];
public:
	~Dog();	//Keyword virtual is optional
	Dog(char*, char*);
	void Move();	//Notice this declaration...override and virtuale are optional
};
Dog::Dog(char* dogName = 0, char* dogType = 0) : Animal(dogName)
{
	if(dogType == 0)
		strcpy_s(type, "Simple");
	else
		strcpy_s(type, dogType);
}
void Dog::Move()
{
	cout << type <<" " << GetName() <<" is RUNNING.\n";
	/*CommonFunctionality();*/
}
Dog::~Dog()
{
	cout << "~Dog() called for " << GetName() << endl;
}
//----------------------------------------------------------------
class Turtle : public Animal
{
private:
	char mask_color[20];
public:
	~Turtle();	//Keyword virtual is optional
	Turtle(char*,char*);
	void Move(); //Notice this declaration...override and virtual are optional
};
Turtle::Turtle(char* turtleName, char* color) : Animal(turtleName)
{	
	if(color == 0)
		strcpy_s(mask_color, "Blue");
	else
		strcpy_s(mask_color, color);
}
void Turtle::Move()
{
	cout << mask_color << " " << GetName() << " is CRAWLING.\n";
	//CommonFunctionality();
}
Turtle::~Turtle()
{
	cout << "~Turtle() called for "<< GetName()<<endl;
}

void main()
{
	Animal* animals[5];

	//Base Class Pointers pointing to Derived Class Objects
	animals[0] = new Dog;	
	animals[1] = new Turtle("Donnie", "Purple");
	animals[2] = new Dog("Poni", "Simple");
	animals[3] = new Turtle("Leo", "Blue");
	animals[4] = new Turtle("Mikey", "Orange");

	for (int i = 0; i < 5; i++)
	{
		animals[i]->Move();	//Polymorphism		
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		delete animals[i];
		cout << endl;
	}
	
	//Homework: Remove keyword virtual from Destructors and Move function and note the program behavior
}