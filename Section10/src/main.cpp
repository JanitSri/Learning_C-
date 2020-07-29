#include <iostream> 
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <string>
#define deb(x) cout << #x << " " << x << endl;
using namespace std;

int main(int argv, char *argc[]){
	
	/*
	char name[50] = "Janit";
	cout << name << endl; 
	cout << "Enter your full name: ";
	cin.getline(name, 50);
	
	cout << "Welcome " << name << endl;
	cout << "The length of your name is " << strlen(name) << endl;
	
	deb(name);
	
	string s1 {"Janit"};
	string s2 {"Janit", 3};
	string s3 {"Janit", 0, 1};
	string s4 (3, 'X');
	
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	*/
	
	string alphabet {"abcedfghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVXWYZ"};
	string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgihqdyvtkfuompciasr"};
	
	string text{};
	cout << "Enter text to encode: ";
	getline(cin, text);
	
	cout << "=========CIPHER=========" << endl;
	for(size_t i = 0; i < text.length(); i++){
		if(isspace(text[i]))
			continue;
		text[i] = key[alphabet.find(text[i])];
	}
	cout << text << endl;
	
	return 0;
}






















