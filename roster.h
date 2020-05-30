#include<iostream>
#include<string>
#include<iomanip>
#include "Student.h"
using namespace std;
#pragma once
const int numStudents = 5;



const string studentData[numStudents] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Bradley,Timm,btimm1@wgu.edu,25,30,10,31,SOFTWARE"
};

class Roster
{
public:
	
	int lastIndex;
	int capacity;
	Student* classRosterArray[numStudents] = { nullptr };
	Roster();
	Roster(int capacity);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void parse();
	void printAll();
	void remove(string studentID);
	void printAvgDays(string studentID);
	void printInvalidEmails();//A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();

private:

};

