#include <iostream>
#include "Savings.h"

#define deb(x) cout << #x << " " << x << endl
#define LINEBREAK cout << endl 

using namespace std;

int main(int argv, char* argc[]){
	
	cout << "==========Account==========" << endl;
	Account acc{};
	acc.deposit(2000.00);
	acc.withdraw(500.00);
	cout << acc;
	LINEBREAK;
	
	Account* p_acc{nullptr};
	p_acc = new Account();
	p_acc->deposit(1000.00);
	p_acc->withdraw(500.00);
	delete p_acc;
	LINEBREAK;
	
	cout << "==========Savings==========" << endl;
	Savings sav_acc{};
	sav_acc.deposit(50.00);
	sav_acc.withdraw(500.00);
	cout << sav_acc;
	LINEBREAK;
	
	Savings* p_sav_acc{nullptr};
	p_sav_acc = new Savings();
	p_sav_acc->deposit(1000.00);
	p_sav_acc->withdraw(500.00);
	delete p_sav_acc;
	LINEBREAK;
	
	
	return 0;
}
