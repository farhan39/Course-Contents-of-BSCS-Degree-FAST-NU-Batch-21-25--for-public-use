#include<iostream>
using namespace std;

template<typename T>	//T is template or type parameter
T Sum(T a, T b)
{
	cout << "Sum of T and T called." << endl;
	return a + b;
}

template<typename T1, typename T2>	//T1 and T2 are template or type parameter
T1 Sum(T1 a, T2 b)
{
	cout << "Sum of T1 and T2 called." << endl;
	return a + b;
}

template<class identifier>	//identifier is template or type parameter
identifier Product(identifier a, identifier b)
{
	return a * b;
}

void main()
{
	int i = 10, j = 20, k;
	float l = 10.5, m = 20.2, n;

	k = Sum<int>(i, j);
	n = Sum<float>(l, m);
	//ComplexNumber abc = Sum(c1,c2); //Will this work???
	//ComplexNumber abc = Sum(i,c1); //Will this work???
	cout << "k = " << k << endl;
	cout << "n = " << n << endl;

	//This is same as above
	//k = Sum(i, j);
	//n = Sum(l, m);
	//cout << "k = " << k << endl;
	//cout << "n = " << n << endl;

	//Function Overloading VS Function Templates	
	k = Sum(j, m);
	cout << "k = " << k << endl;


}