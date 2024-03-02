#include<iostream>
using namespace std;

//Properties of Static Members
//Each object has its own copy of all the data.
//If we want one copy of a variable to be shared by all the objects, make it static
// Static data is class-wide information.
//static data has class scope
//must be initialized exactly once
class Monster
{
private:	
	static int monstersCount;		//declaration of static data member in class
	char name[20];
public:
	Monster(char*);
	void Attack();
	static int GetMonstersCount();	//Static function
	~Monster();
};
//Define and initialize static data member (private or public) in global scope 
int Monster::monstersCount = 0;

Monster::Monster(char* monsterName = "Monster")
{
	cout << monsterName << " created.\n";
	strcpy_s(name, monsterName);
	monstersCount++;
}
Monster::~Monster()
{
	cout <<"~Monster() called for "<< name <<endl;
	monstersCount--;
}
void Monster::Attack()
{
	if (monstersCount < 5)
	{
		cout << name <<" is Coward.\n";
	}		
	else
	{
		cout << name <<" killed a space creature.\n";
	}
}
//Static member function does not get "this" in function call
//Static member function cannot access any non-static member. Why?
int Monster::GetMonstersCount()
{
	//Uncomment this line and see what happens
	//strcpy(name, "abc");
	return monstersCount;
}
void main()
{
	cout << "Game Started\n";

	//Static Member Function can be called without using an objet
	//Static data exists without any object's creation
	cout << "Monsters Count:\t" << Monster::GetMonstersCount()<<endl; //Static data belongs to class not to object
	//Static function is service of a class, not of an object.

	Monster m1("Water Zombie");
	m1.Attack();

	cout << "Size of m1:\t" << sizeof(m1) << endl;

	Monster* m2 = new Monster("Red Devil");
	m2->Attack();
	cout << "Mosters Count:\t" << m2->GetMonstersCount()<<endl;	//Static Members can be used using objects of class

	delete m2;
	cout << "Mosters Count:\t" << m1.GetMonstersCount()<<endl;
	
	Monster* monstersGroup = new Monster[5];

	m1.Attack();
	cout << "Mosters Count:\t" << monstersGroup->GetMonstersCount()<<endl;// What is this line doing
	
	if(monstersGroup)//mosterGroup != 0
		delete[] monstersGroup;
	cout << "Monsters Count:\t" << Monster::GetMonstersCount() << endl;
}