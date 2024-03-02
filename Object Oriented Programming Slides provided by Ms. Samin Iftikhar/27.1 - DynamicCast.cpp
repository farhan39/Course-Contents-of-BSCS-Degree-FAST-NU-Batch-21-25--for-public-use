//Dynamic_cast page 553 Dietel&Dietel
#include<iostream>
using namespace std;

class Animal{	
public:
	virtual void Move() = 0;//Pure Virtual
	virtual void PrintInfo()
	{
		cout<<"Animal PrintInfo"<<endl;
	}
};

class Dog : public Animal
{
public:
	void Move(){
		cout<<"Dog Running"<<endl;
	}
	void PrintInfo(){
		cout<<"Dog Type...\n";
	}
};
class Turtle: public Animal
{
public:
	void Move()
	{
		cout<<"Turtle Crawling...\n";
	}
	void PrintInfo()
	{
		cout<<"Turtle Mask Color\n";
	}
};
class Rabbit: public Animal
{
public:
	void RabbitSpecificFunction(){
		cout<<"Rabbit Specific Function\n";
	}
	void Move()
	{
		cout<<"Rabbit Jumping\n";
	}
};

void DoSomething(Animal* ptr)
{
	ptr->Move();
	ptr->PrintInfo();
	Rabbit *derivedPtr = dynamic_cast < Rabbit * >( ptr );
	if ( derivedPtr != nullptr ) // true for "is a" relationship
	{
		derivedPtr->RabbitSpecificFunction();
	}

}
void main()
{
	Animal* animals[4];

	animals[0] = new Dog;
	animals[1] = new Turtle;
	animals[2] = new Rabbit;
	animals[3] = new Rabbit;

	for(int i=0 ; i<4 ; i++)
	{
		//animals[i]->Move();
		//animals[i]->PrintInfo();
		DoSomething(animals[i]);
		cout<<"\n\n";
	}
}