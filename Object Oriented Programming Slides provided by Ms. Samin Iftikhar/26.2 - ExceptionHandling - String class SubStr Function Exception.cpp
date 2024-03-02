//#include<iostream>
//#include<string>
//using namespace std;
//
//void Test1()
//{
//	string sentence;
//	string str1;
//
//	sentence = "Testing String Exceptions!";
//	cout<<sentence<<endl;
//	cout<<sentence.length()<<endl;
//
//
//	str1 = sentence.substr(8,50);	// 	Copies a substring of at most some number of characters from a string beginning from a specified position.
//	cout<<"SubString:\t"<<str1<<endl;	
//
//	str1 = sentence.substr(28,50);
//	cout<<"SubString:\t"<<str1<<endl;		
//}
//
//void Test2()
//{
//	string sentence;
//	string str1;
//
//	sentence = "Testing String Exceptions!";
//	cout<<sentence<<endl;
//	cout<<sentence.length()<<endl;	
//
//	try
//	{
//		str1 = sentence.substr(8,50);	// 	Copies a substring of at most some number of characters from a string beginning from a specified position.
//		cout<<"SubString:\t"<<str1<<endl;	
//
//		str1 = sentence.substr(28,50);
//		cout<<"SubString:\t"<<str1<<endl;	
//	}
//	catch(out_of_range& re)	//Why we are taking re by reference???
//	{
//		cout<<"--------Error Occured:\t"<<re.what()<<endl;
//	}
//	
//	cout<<"This line is after catch block..."<<endl;
//}
//
//void main()
//{
//	//Test only one function at a time. Debug the code to see what exactly it is doing
//	//Test1();
//
//	Test2();
//}