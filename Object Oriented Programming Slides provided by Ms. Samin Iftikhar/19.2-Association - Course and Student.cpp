#include <iostream>
using namespace std;
const int maxStudents = 50;

class Course;
class Student;


class Student{
	char RollNo[10];
	char Name[50];
	Course* RegisteredCourses[5];
	int courseCount;
public:
	Student(char* _rollno, char* _name);
	void RegisterCourse(Course* crsPtr);
	void PrintListView();
	void PrintAllCourses();
};

class Course{
	char Code[10];
	char Name[50];
	int CreditHours;
	Student* StudentList[maxStudents];
	int RegisteredStudents;
public:
	Course(char* _name, char* _code);
	void RegisterStudent(Student* stdPtr);
	void PrintAll();
	void PrintListView();
};
//-------------------------------------------------------
Course::Course(char* _name, char* _code)
	{
		strcpy_s(Name,_name);
		strcpy_s(Code,_code);
		for(int i = 0; i<maxStudents ; i++)
		{
			StudentList[i] = 0;
		}
		RegisteredStudents = 0;
	}
	void Course::RegisterStudent(Student* stdPtr)
	{
		StudentList[RegisteredStudents] = stdPtr;
		RegisteredStudents++;
	}
	void Course::PrintAll()
	{
		for(int i = 0; i<RegisteredStudents ; i++)
		{
			StudentList[i]->PrintListView();
		}
	}	
	void Course::PrintListView()
	{
		cout<<Code<<"\t\t"<<Name<<endl;
	}
//-------------------------------------------------------
	Student::Student(char* _rollno, char* _name)
	{
		strcpy_s(Name,_name);
		strcpy_s(RollNo,_rollno);
		for(int i = 0 ; i<5 ; i++)
			RegisteredCourses[i] = 0;
		courseCount = 0;
	}

	void Student::RegisterCourse(Course* crsPtr)
	{
		RegisteredCourses[courseCount] = crsPtr;
		courseCount++;
	}

	void Student::PrintListView()
	{
		cout<<RollNo<<"\t\t"<<Name<<endl;
	}
	void Student::PrintAllCourses()
	{
		for(int i = 0; i<courseCount ; i++)
		{
			RegisteredCourses[i]->PrintListView();
		}
	}
//-------------------------------------------------------

void main()
{
	Course oop("Object Oriented Programming", "CS217");
	Course la("Linear Algebra", "MT118");

	Student s1("20L1234", "Abc Xyz");

	s1.RegisterCourse(&oop);
	oop.RegisterStudent(&s1);

	s1.RegisterCourse(&la);
	la.RegisterStudent(&s1);

	oop.PrintAll();

	s1.PrintAllCourses();
	//Test Your Concepts
	//Drop Course Functionality?
}



