#pragma once 
#include "Savings.h"

class Trust: public Savings{
	friend std::ostream& operator<<(std::ostream& out, const Trust& account);
	
	private:
		static constexpr const char* def_name = "Unnamed Savings Account";
		static constexpr double def_balance = 0.0;
		static constexpr double deposit_thres = 5000.0;
		static constexpr double deposit_bonus = 50.0;
		int number_of_withdrawals = 3;
	public:
		Trust(std::string name = def_name, double balance = def_balance);
		bool deposit(double amount);
		bool withdraw(double amount);
};