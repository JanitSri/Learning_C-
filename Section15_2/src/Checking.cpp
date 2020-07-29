#include "Checking.h"

Checking::Checking(std::string name, double balance)
	: Account{name, balance}{}

bool Checking::withdraw(double amount){
	amount += withdrawal_fee;
	return Account::withdraw(amount);
}

std::ostream& operator<<(std::ostream& out, const Checking& account){
	out << "Checking Account -> [" << "Name:" << account.name << ",Balance:" << account.balance << "]";
	return out;
}