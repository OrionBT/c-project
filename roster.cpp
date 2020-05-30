#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#include<cstring>
#include<vector>
#include"roster.h"
using namespace std;

Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	
}

void Roster::parse()
{
	for (int i = 0; i < numStudents; i++) {
		string student = studentData[i];
		stringstream stream(student);

		while (stream.good()) {
			
			string studentID;
			string firstName;
			string lastName;
			string emailAddress;
			string ageStr;
			string daysInCourse1str;
			string daysInCourse2str;
			string daysInCourse3str;
			string degree;
			getline(stream, studentID, ',');
				
			getline(stream, firstName, ',');
				
			getline(stream, lastName, ',');
				
			getline(stream, emailAddress, ',');
				
			getline(stream, ageStr, ',');
				
			int age = stoi(ageStr);
				
			getline(stream, daysInCourse1str, ','); 
			
			int daysInCourse1 = stoi(daysInCourse1str);
				
			getline(stream, daysInCourse2str, ',');
				
		    int daysInCourse2 = stoi(daysInCourse2str);

			getline(stream, daysInCourse3str, ',');

			int daysInCourse3 = stoi(daysInCourse3str);

			getline(stream, degree, ',');
			DegreeProgram degreeProgram;
			if (degree == "SECURITY") {
				degreeProgram = DegreeProgram::SECURITY;
			}
			else if (degree == "NETWORK") {
				degreeProgram = DegreeProgram::NETWORK;
			}
			else if (degree == "SOFTWARE") {
				degreeProgram = DegreeProgram::SOFTWARE;
			}

			add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
		}
	}
	
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int daysCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	Student* student = new Student(studentID, firstName, lastName, emailAddress, age, daysCourse, degreeProgram);
	int j = 0;
	for (int i = 0; i < numStudents; i++) 
	{
		if (classRosterArray[i] == nullptr) 
		{
		classRosterArray[i] = student;
		break;
		}
	}
	

}

void Roster::remove(string studentID)
{
	bool removedStudent = false;
	for (int k = 0; k < numStudents; k++) {
		Student* pupel = classRosterArray[k];
		if (pupel->getID() == studentID) {
			classRosterArray[k] = nullptr;
			removedStudent = true;
		}
		if (removedStudent == false) {
			cout << "Student not found\n";
		}
	}
}

void Roster::printAll()
{
	for (int i = 0; i < numStudents; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printAvgDays(string studentID)
{
	double total = 0;
	int arraySize = 3;
	for (int y = 0; y < numStudents; y++)
	{
		if (classRosterArray[y]->getID() == studentID)
		{
			int* daysInCourse = classRosterArray[y]->getDaysCourse();
			for (int h = 0; h < arraySize; h++)
			{
				total = total + daysInCourse[h];
			}
			cout << "Student " << classRosterArray[y]->getID() << " spent an average of" << (total / arraySize) << " days in each course.\n";
		}
	}
}

void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails:" << endl;
	for (int i = 0; i < numStudents; i++) {
		bool foundCharAt = false;
		bool foundCharPeriod = false;
		bool foundCharSpace = false;
		string email = "";
		email = classRosterArray[i]->getEmail();
		for (char& c : email) {
			if (c == '@') {
				foundCharAt = true;
			}
			if (c == '.') {
				foundCharPeriod = true;
			}
			if (c == ' ') {
				foundCharSpace = true;
			}
		}
		if (foundCharAt == false || foundCharPeriod == false || foundCharSpace == true) {
			cout << classRosterArray[i]->getEmail();
		}
		cout << endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{

	
	cout << "Printing students in degreeProgram " << degreeProgramStrings[degreeProgram] << "\n";
	for (int t = 0; t <= numStudents; t++) {
		if (this->classRosterArray[t]->getDegreeProgram() == degreeProgram) this->classRosterArray[t]->print();
	}
}

Roster::~Roster()
{
for (int i = 0; i < numStudents; i++)
{
	delete this->classRosterArray[i];
	}
delete this;
}
