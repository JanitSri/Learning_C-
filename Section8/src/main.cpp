#include <iostream>


using namespace std;

int main(int argc, char *argv[]){
	
	/*
	int num1 {}, num2 {};
	const int count {2};
	double total {};
	
	cout << "Enter two numbers seperated spaces: ";
	
	cin >> num1 >> num2;
	
	total = (num1+num2) / static_cast<double>(count);
	
	cout << "The average of the numbers is " << total << "." << endl; 
	*/
	
	int cents {};
	
	cout << "Enter the number of cents: ";
	
	cin >> cents;
	
	cout << "Cents: " << cents << endl;
	cout << "Dollars: " << cents/100 << endl;
	cout << "Quarters: " << (cents%100)/25 << endl;
	cout << "Dimes: " << (cents%100%25)/10 << endl;
	cout << "Nickels: " << (cents%100%25%10)/5 << endl;
	cout << "Pennies: " << (cents%100%25%10%5)/1 << endl;
	
	return 0;
}