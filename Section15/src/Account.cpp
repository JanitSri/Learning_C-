#include <iostream>
#include "Account.h"

Account::Account(std::string name, double balance)
	: name{name}, balance{balance}{}

Account::Account()
	: Account{"Janit", 1000.00}{}

Account::~Account(){}

void Account::deposit(double amount){
	std::cout << "Account Deposit called with " << amount << std::endl;
	this->balance += amount;
}

void Account::withdraw(double amount){
	std::cout << "Account Withdraw called with " << amount << std::endl;
	this->balance -= amount;
}

std::ostream& operator<<(std::ostream& out, const Account& rhs){
	out <<  "Name:" << rhs.name << " Balance:" << rhs.balance << std::endl;
	return out;
}