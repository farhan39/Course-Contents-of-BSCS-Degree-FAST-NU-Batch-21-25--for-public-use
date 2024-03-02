#include<iostream>
using namespace std;

int globalVar = 0;

void Test()
{
	int localVar = 10;		//Life starts and ends in this function. Scope within this function
	static int staticVar = 0;		//Life starts and ends with program. Scope within this function.
	cout << "localVar:\t" << localVar << endl;	
	cout << "globalVar:\t" << globalVar << endl;
	cout << "staticVar:\t" << staticVar << endl;
	
	localVar++;
	staticVar++;
	globalVar++;
}

void main()
{
	globalVar = 20;
	cout << "globalVar:\t" << globalVar << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		Test();
		globalVar++;
		cout << "globalVar:\t" << globalVar << endl << endl;
	}
}