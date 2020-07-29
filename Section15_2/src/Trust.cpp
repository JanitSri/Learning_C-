#include "Trust.h"

Trust::Trust(std::string name, double balance)
	: Savings{name,balance,0.0}{}

bool Trust::deposit(double amount){
	if((amount - deposit_thres) >= 0){
		amount += deposit_bonus;
	}
	return Savings::deposit(amount);
}

bool Trust::withdraw(double amount){
	if(number_of_withdrawals <= 0){
		return false;
	}
	
	number_of_withdrawals--;
	return Savings::withdraw(amount);
}

std::ostream& operator<<(std::ostream& out, const Trust& account){
	out << "Trust Account -> [" << "Name:" << account.name << ",Balance:" << account.balance << "]";
	return out;
}