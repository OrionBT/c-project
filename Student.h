#include <iostream>
#include <string>
#include "degree.h"
#pragma
using namespace std;
class Student
{
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysCourse[3];
	DegreeProgram degreeProgram;
	int switchFunction(DegreeProgram degree);
public:
	const static int dayCourseArraySize = 3;
	Student();
	Student(string ID, string firstName, string lastName, string emailAddress, int age, int daysCourse[], DegreeProgram degreeProgram);

	//getters for each variable
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int * getDaysCourse();
	DegreeProgram getDegreeProgram();

	//setters for each variable
	void setID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string emailAddress);
	void setAge(int age);
	void setDaysCourse(int daysCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);
	void print();

	//destructor
	~Student();
};
