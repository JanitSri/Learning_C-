#include <iostream>
#include <string>
#include "Mystring.h"

#define deb(x) cout << #x << " " << x << endl
#define LINEBREAK cout << endl

using namespace std;


int main(int argv, char* argc[]){
	Mystring empty;
	Mystring larry{"Larry"};
	Mystring stooge{larry};
	
	empty.display();
	larry.display();
	stooge.display();
	
	LINEBREAK;
	// Overloading the assignment operator (copy, l-value)
	Mystring a{"Hello"};
	Mystring b;
	
	b = a;
	b.display();
	
	LINEBREAK;
	// Overloading the assignment operator (move, r-value)
	Mystring c;
	c = Mystring{"Hola"};
	c.display();
	
	LINEBREAK;
	// Overloading the unary operator (pre-decrement)
	Mystring janit{"JANIT"};
	janit.display();
	janit = -janit;
	janit.display();
	
	
	LINEBREAK;
	// Overloading the stream operators 
	Mystring larrie("Larry");
	Mystring moe("Moe");
	Mystring curly;
	
	cout << "Enter the name of the third stooge: ";
	cin >> curly;
	
	cout << "The three stooges are " << larrie << ", " << moe << ", and " << curly << endl;
		
	cout << "Enter the name of the three stooges seperated by space: ";
	cin >> larrie >> moe >> curly;
	
	cout << "The three stooges are " << larrie << ", " << moe << ", and " << curly << endl;
	
	LINEBREAK;
	Mystring abc{"abc"};
	abc = abc * 3;
	cout << abc << endl; 
	
	LINEBREAK;
	return 0;
}

















