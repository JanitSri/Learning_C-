#pragma once 
#include "Account.h"

class Checking: public Account{
	friend std::ostream& operator<<(std::ostream& out, const Checking& account);
	
	private:
		static constexpr const char* def_name = "Unnamed Savings Account";
		static constexpr double def_balance = 0.0;
		static constexpr double withdrawal_fee = 1.50;
	public:
		Checking(std::string name = def_name, double balance = def_balance);
		bool withdraw(double amount);
};