#include <iostream>
#include "Account.h"

// cpp file - holds the implementation for the class 

int Account::accounts_active = 0; // static variable 

Account::Account(std::string name, double balance) // constructor intialization lists 
	: name{name}, balance{balance}{
		accounts_active++;
} 

Account::Account() // delegating constructors 
	: Account{"Janit", 1000.00}{} 

Account::Account(std::string name)
	: Account{name, 1000.00}{}

Account::Account(double balance)
	: Account{"Janit", balance}{}

Account::Account(const Account &source) // copy constructor implementation (shallow implementation)
	: name{source.name}, balance{source.balance}{
	std::cout << "Copy constructor...made a copy of " << source.name << std::endl;
}

// Note: Deep Copy must be implemented when raw pointers are used 

Account::~Account(){
	std::cout << "Destructor called..." << std::endl;
	accounts_active--;
}

int Account::get_active_accounts(){  // static method 
	return accounts_active;
}

void Account::set_balance(double balance){
	this->balance = balance;
}

double Account::get_balance() const{
	return balance; 
}

void Account::set_name(std::string n){
	name = n;
}

std::string Account::get_name() const{
	return name;
}

bool Account::deposit(double amount){
	balance += amount;
	return true;
}

bool Account::withdraw(double amount){
	if(balance-amount >= 0){
		balance -= amount;
		return true;
	}
	return false;
}

bool Account::check_accounts(const Account &other){
	// 'this' is a pointer to the current object 
	return this == &other;
}





