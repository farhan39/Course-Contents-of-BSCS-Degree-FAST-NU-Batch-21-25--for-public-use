//#include<iostream>
//#include<string>
//using namespace std;
//
//class MyString
//{
//	friend ostream& operator<<(ostream& out, MyString& obj);
//	char* str;
//public:
//	MyString(char* s = "")
//	{
//		int size = strlen(s);
//		str = new char[size+1];
//		int i = 0;
//		for(; i<size;i++)
//			str[i] = s[i];
//		str[i] = '\0';		
//	}
//	~MyString()
//	{
//		if(str)
//			delete[] str;		
//	}
//
//	//Following function is for test case 1
//	//char& operator[](int i)
//	//{
//	//	return str[i];
//	//}
//
//	//Following function is for test case 2
//	char& operator[](int i)
//	{
//		if(i>=0 && i<strlen(str))
//			return str[i];
//		else
//		{
//			//What should function do in this case???
//			throw out_of_range("Index Out Of Range occured in operator[]");
//		}
//	}
//};
//ostream& operator<<(ostream& out, MyString& obj)
//{
//	out<<obj.str;
//	return out;
//}
//void Test1()
//{
//		MyString str1("Hello");
//		
//		str1[4] = 'O';
//		cout<<str1<<endl;
//
//		str1[100] = '$';	//Writing out of bound
//		cout<<str1<<endl;
//}
//void Test2()
//{
//	try
//	{
//		MyString str1("Hello");
//		
//		str1[4] = 'O';
//		cout<<str1<<endl;
//
//		str1[100] = '$';
//		cout<<str1<<endl;
//	}
//	// List of Catch Blocks....
//	catch(out_of_range& ex)	//Why we are taking ex by reference???
//	{
//		cout<<"--------Error Occured:\t"<<ex.what()<<" in Test2."<<endl;
//	}
//	catch(exception& ex) //What if we have only this catch? Or this catch is first in the list of catch blocks???
//	{
//		cout<<"--------Error Occured:\t"<<ex.what()<<" in Test2."<<endl;
//	}
//}
//
//void main()
//{
//	//Test following functions one by one
//	//Test1();
//	Test2();
//
//}