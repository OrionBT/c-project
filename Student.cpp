#include<iostream>
#include<string>
#include<iomanip>
#include "Student.h"
using namespace std;

Student::Student()//Empty constructor
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
}

Student::Student(string ID, string firstName, string lastName, string emailAddress, int age, int daysCourse[], DegreeProgram degreeprogram) {
	this->studentID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;

	for (int i = 0; i < dayCourseArraySize; i++)
	{
		this->daysCourse[i] = daysCourse[i];
	}
	this->degreeProgram = degreeProgram;
	
}

//getter functions
string Student::getID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmail()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int * Student::getDaysCourse()
{
	return daysCourse;
}

DegreeProgram Student::getDegreeProgram()
{
	return degreeProgram;
}

//setter functions

void Student::setID(string ID)
{
	studentID = ID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmail(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setDaysCourse(int daysCourse[])
{
	for (int i = 0; i < dayCourseArraySize; i++) 
	{
		this->daysCourse[i] = daysCourse[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

int Student::switchFunction(DegreeProgram degree) 
{
	switch (degree) {
	case DegreeProgram::SECURITY:
		return 1;
		break;
	case DegreeProgram::NETWORK:
		return 2;
		break;
	case DegreeProgram::SOFTWARE:
		return 3;
		break;
	default:
		return 0;
		break;
	}
}
/*void Student::print()
{
	cout << studentID << "\t"<< firstName << "\t" << lastName << "\t" << emailAddress<< "\t"<< age<< "\t" << daysCourse[0]<<"\t"<<daysCourse[1]<<"\t"<<daysCourse[2];
	
}*/
void Student::print()
{
	cout << left << setw(2) << studentID;
	cout << left << setw(10) << firstName;
	cout << left << setw(20) << lastName;
	cout << left << setw(50) << emailAddress;
	cout << left << setw(3) << age;
	cout << left << setw(3) << daysCourse[0];
	cout << left << setw(3) << daysCourse[1];
	cout << left << setw(3) << daysCourse[2];
	cout << left << setw(20) << getDegreeProgram();//degreeProgramStrings[switchFunction(getDegreeProgram())];
}

Student::~Student()
{
	if (daysCourse != nullptr) {
		delete[] daysCourse;
	}
}
