#include<iostream>
#include"roster.h"

using namespace std;
int main(){
	cout << "SCRIPTING AND PROGRAMMING - APPLICATIONS - C867" << endl;
	cout << "C++" << endl;
	cout << "001313056" << endl;
	cout << "Bradley Timm" << endl;
	Roster classRoster;
	
	classRoster.parse();
	classRoster.printAll();
	return 0; 
	
}
