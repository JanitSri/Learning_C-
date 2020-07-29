#pragma once 
#include<string>
#include<iostream>

class Account{
	friend std::ostream& operator<<(std::ostream& out, const Account& account);
	
	private:
		static constexpr const char* def_name = "Unnamed Account";
		static constexpr double def_balance = 0.0;
	protected:
		std::string name;
		double balance;
	public:
		Account(std::string name = def_name,double balance = def_balance);
		bool deposit(double amount); 
		bool withdraw(double amount); 
		double get_balance() const; 
};