#include "Savings.h"

Savings::Savings(std::string name, double balance, double int_rate)
	: Account{name,balance}, int_rate{int_rate}{}

bool Savings::deposit(double amount){
	amount += (amount * int_rate / 100);
	return Account::deposit(amount);
}

std::ostream& operator<<(std::ostream& out, const Savings& account){
	out << "Savings Account -> [" << "Name:" << account.name << ",Balance:" << account.balance << ",Interest Rate:" << account.int_rate << "]";
	return out;
}