#pragma once 
#include "Account.h"

class Savings: public Account{
	friend std::ostream& operator<<(std::ostream& out, const Savings& account);
	
	private:
		static constexpr const char* def_name = "Unnamed Savings Account";
		static constexpr double def_balance = 0.0;
		static constexpr double def_int_rate = 0.0;
	protected:
		double int_rate;
	public:
		Savings(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
		bool deposit(double amount);
};