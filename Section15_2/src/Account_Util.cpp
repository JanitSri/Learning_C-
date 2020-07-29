#include "Account_Util.h"
#include <iostream>

void display(const std::vector<Account>& accounts){
	for(const Account& acc: accounts){
		std::cout << acc << std::endl; 
	}
}

void deposit(std::vector<Account>& accounts, double amount){
	std::cout << "==============Deposit into Account==============" << std::endl;
	for(Account& acc: accounts){
		if(acc.deposit(amount)){
			std::cout << "Deposit Successful for " << acc << std::endl; 
		}
		else{
			std::cout << "Failed to Deposit for " <<  acc << std::endl; 
		}
	}
}

void withdraw(std::vector<Account>& accounts, double amount){
	std::cout << "==============Withdraw from Account==============" << std::endl;
	for(Account& acc: accounts){
		if(acc.withdraw(amount)){
			std::cout << "Withdraw Successful for " << acc << std::endl; 
		}
		else{
			std::cout << "Failed to Withdraw for " << acc << std::endl; 
		}
	}
}

void display(const std::vector<Savings>& accounts){
	for(const Savings& acc: accounts){
		std::cout << acc << std::endl; 
	}
}

void deposit(std::vector<Savings>& accounts, double amount){
	std::cout << "==============Deposit into Savings Account==============" << std::endl;
	for(Savings& acc: accounts){
		if(acc.deposit(amount)){
			std::cout << "Deposit Successful for " << acc << std::endl; 
		}
		else{
			std::cout << "Failed to Deposit for " <<  acc << std::endl; 
		}
	}
}

void withdraw(std::vector<Savings>& accounts, double amount){
	std::cout << "==============Withdraw from Savings Account==============" << std::endl;
	for(Savings& acc: accounts){
		if(acc.withdraw(amount)){
			std::cout << "Withdraw Successful for " << acc << std::endl; 
		}
		else{
			std::cout << "Failed to Withdraw for " << acc << std::endl; 
		}
	}
}

void display(const std::vector<Checking>& accounts){
	for(const Checking& acc: accounts){
		std::cout << acc << std::endl; 
	}
}

void deposit(std::vector<Checking>& accounts, double amount){
	std::cout << "==============Deposit into Checking Account==============" << std::endl;
	for(Checking& acc: accounts){
		if(acc.deposit(amount)){
			std::cout << "Deposit Successful for " << acc << std::endl; 
		}
		else{
			std::cout << "Failed to Deposit for " <<  acc << std::endl; 
		}
	}
}

void withdraw(std::vector<Checking>& accounts, double amount){
	std::cout << "==============Withdraw from Checking Account==============" << std::endl;
	for(Checking& acc: accounts){
		if(acc.withdraw(amount)){
			std::cout << "Withdraw Successful for " << acc << std::endl; 
		}
		else{
			std::cout << "Failed to Withdraw for " << acc << std::endl; 
		}
	}
}


void display(const Trust& acc){
	std::cout << acc << std::endl; 
}

void deposit(Trust& acc, double amount){
	std::cout << "==============Deposit into Trust Account==============" << std::endl;	
	if(acc.deposit(amount)){
		std::cout << "Deposit Successful for " << acc << std::endl; 
	}
	else{
		std::cout << "Failed to Deposit for " <<  acc << std::endl; 
	}

}

void withdraw(Trust& acc, double amount){
	std::cout << "==============Withdraw from Checking Account==============" << std::endl;
	if(acc.withdraw(amount)){
		std::cout << "Withdraw Successful for " << acc << std::endl; 
	}
	else{
		std::cout << "Failed to Withdraw for " << acc << std::endl; 
	}
}




