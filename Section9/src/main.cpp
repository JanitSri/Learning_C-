#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int args, char *argv[]){
	
	/*
	int age{};
	cout << "Enter your age: ";
	cin >> age;
	
	string message{"You can drive!!!"};
	if(age < 16){
		message = "You cannot drive!!!";
	}
	
	cout << message << endl;
	*/
	
	for(int i = 1; i <= 10; i++){
		cout << i << endl;
	}
	
	vector<int> grades {90,95,99,95,97};
	
	cout << "Your Grades are:" << endl;
	for(int grade: grades){
		cout << grade << endl;
	}
	
	return 1;
}
