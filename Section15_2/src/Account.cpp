#include "Account.h"

Account::Account(std::string name,double balance)
	: name{name}, balance{balance}{}

bool Account::deposit(double amount){
	if(amount > 0){
		balance += amount;
		return true;
	}
	return false;
}

bool Account::withdraw(double amount){
	if(balance - amount >= 0){
		balance -= amount;
		return true;
	}
	return false;
}

double Account::get_balance() const{
	return balance;
}

std::ostream& operator<<(std::ostream& out, const Account& account){
	out << "Account -> [" << "Name:" << account.name << ",Balance:" << account.balance << "]";
	return out;
}