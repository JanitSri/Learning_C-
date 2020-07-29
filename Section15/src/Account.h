#pragma once 
#include <string>

class Account{
	friend std::ostream& operator<<(std::ostream& out, const Account& rhs);
	
	public:
		std::string name;
		double balance;
		Account();
		Account(std::string name, double balance);
		~Account();
		void deposit(double amount);
		void withdraw(double amount);
};