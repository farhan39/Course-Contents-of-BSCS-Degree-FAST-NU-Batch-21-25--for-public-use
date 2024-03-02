//#include<iostream>
//using namespace std;
//
//void Test1()
//{
//	int* ptr[50];
//	for (int i = 0; i < 50; i++)
//	{
//		ptr[i] = new int[50000000];
//		cout << ptr[i] <<endl;
//	}
//}
//void Test2()
//{
//	int* ptr[50];
//
//	try
//	{
//		for (int i = 0; i < 50; i++)
//		{
//			ptr[i] = new int[50000000];
//			cout << ptr[i] <<endl;
//		}
//	}
//	catch (bad_alloc& memoryAllocationException)
//	{
//		cerr << "Exception occured:\t" << memoryAllocationException.what() << " in Test2()." << endl;
//	}
//}
//void main()
//{
//	Test one function at a time
//	//Test1();
//	Test2();
//}