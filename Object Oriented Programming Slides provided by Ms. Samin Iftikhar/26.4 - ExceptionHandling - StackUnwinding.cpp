//#include<iostream>
//#include<stdexcept>
//using namespace std;
//
//void Function3()
//{
//	cout << "Function 3 Start.\n";
//
//	throw runtime_error("Runtime error occured in Function 3.\n");
//
//	cout << "Function 3 End.\n";
//}
//
//
//void Function1()
//{
//	cout << "Function 1 Start.\n";
//
//	Function3();
//
//	cout << "Function 1 End.\n";
//}
//
//void Function11()
//{
//	cout << "Function 11 Start.\n";
//	try{
//	Function3();
//	}
//	catch /*(runtime_error& ex)*/ (bad_alloc& ex) /*(exception& ex)*/
//	{
//		cout << "Exception occured:\t" << ex.what() << endl;
//	}
//
//	cout << "Function 11 End.\n";
//}
//
//void Test1()
//{
//	cout << "Test 1 Start...\n";
//	Function1();
//	
//	cout << "Test 1 End...\n";
//}
//
//void Test2()
//{
//	try
//	{
//		cout << "Test 2 Start.\n";
//		//Function1();
//		Function11();
//		cout << "I am back from Function 1.\n";
//	}
//	catch (runtime_error& ex)
//	{
//		cout << "Exception occured:\t" << ex.what() << endl;
//	}
//	cout<<"Test 2 End...\n";
//}
//
//
//void main()
//{
//	//Test1();
//	Test2();
//}