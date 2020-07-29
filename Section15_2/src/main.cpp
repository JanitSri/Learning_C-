#include <iostream>
#include <vector>
#include "Checking.h"
#include "Trust.h"
#include "Account_Util.h"

#define LINEBREAK cout << endl;
#define SUCCESS std::cout << "Withdrawal Successful"<< std::endl
#define FAIL std::cout << "Withdrawal Failed" << std::endl



using namespace std;

int main(int argv, char* argc[]){
	cout.precision(2);
	cout << fixed;
	
	vector<Account> accounts;
	accounts.push_back(Account{});
	accounts.push_back(Account{"Larry"});
	accounts.push_back(Account{"Moe", 2000});
	accounts.push_back(Account{"Curly", 5000});
	
	display(accounts);
	LINEBREAK;
	withdraw(accounts, 1000);
	LINEBREAK;
	deposit(accounts, 2000);
	LINEBREAK;
	
	vector<Savings> sav_accounts;
	sav_accounts.push_back(Savings{});
	sav_accounts.push_back(Savings{"Superman"});
	sav_accounts.push_back(Savings{"Batman", 2000});
	sav_accounts.push_back(Savings{"Wonderwoman", 5000, 5.0});
	
	display(sav_accounts);
	LINEBREAK;
	deposit(sav_accounts, 1000);
	LINEBREAK;
	withdraw(sav_accounts, 2000);
	LINEBREAK;
	
	vector<Checking> checking_accounts;
	checking_accounts.push_back(Checking{});
	checking_accounts.push_back(Checking{"Lebron"});
	checking_accounts.push_back(Checking{"Micheal", 2000});
	checking_accounts.push_back(Checking{"Kobe", 5000});
	
	display(checking_accounts);
	LINEBREAK;
	deposit(checking_accounts, 1000);
	LINEBREAK;
	withdraw(checking_accounts, 2000);
	LINEBREAK;
	
	
	Trust my_account{"Janit", 1000} ;
	display(my_account);
	LINEBREAK;
	
	if(my_account.withdraw(20)){
		SUCCESS;
	}
	else{
		FAIL;
	}
	
	display(my_account);
	LINEBREAK;
	
	if(my_account.withdraw(20)){
		SUCCESS;
	}
	else{
		FAIL;
	}
	
	display(my_account);
	LINEBREAK;
	
	if(my_account.withdraw(20)){
		SUCCESS;
	}
	else{
		FAIL;
	}
	
	display(my_account);
	LINEBREAK;
	
	if(my_account.withdraw(20)){
		SUCCESS;
	}
	else{
		FAIL;
	}
	
	display(my_account);
	LINEBREAK;
	
	my_account.deposit(1000);
	display(my_account);
	LINEBREAK;
	
	my_account.deposit(5000);
	display(my_account);
	LINEBREAK;
	
	
	return 0;
}

















