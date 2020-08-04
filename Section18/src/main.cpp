#include <iostream>
#include <string>


#define LINEBREAK cout << endl

using namespace std;


class DivideByZeroEception{};

class NegativeValueException{};

class IllegalBalanceException
{
public:
	IllegalBalanceException() = default;
	~IllegalBalanceException() = default;
	
};

class InsufficientFundsException : public std::exception
{
public:
	InsufficientFundsException() noexcept = default;
	~InsufficientFundsException() = default;
	
	virtual const char* what() const noexcept{
		return "Insufficent Balance Exception";
	}
};

class Account
{
friend ostream& operator<<(ostream& os, const Account& acct);
private:
	double balance;
	string name;
public:
	Account(double balance,string name)
		: balance{balance}, name{name}{
			if(balance < 0){
				throw IllegalBalanceException{};
			}
		}
	
	Account()
		: balance{1000.00}, name{"Janit"} {}
	
	~Account(){cout << "Destructor Called for " << name << endl;}
	
	
	double getBalance() const {return balance;}
	string getName() const {return name;}
	void deposit(double amt){
		if(amt > 0){
			this->balance += amt;
			cout << "Deposited " << amt << endl;
		}
	}
	void withdraw(double amt){ 	
		if(balance-amt > 0){
			this->balance -= amt;
			cout << "Withdrawed " << amt << endl;
		}
		else{
			throw InsufficientFundsException{};
		}
	}
};

ostream& operator<<(ostream& os, const Account& acct){
	cout << "ACCOUNT INFORMATION --- Name:" << acct.getName() << " Balance:" << acct.getBalance() << endl;
	return os;
}

double calculate_mpg(int miles, int gallon){
	if(gallon == 0)
		throw DivideByZeroEception();
	if(gallon < 0 || miles < 0)
		throw NegativeValueException();
	return static_cast<double>(miles)/gallon;
}

int main(int argv, char* argc[]){
	/*
	int miles{}, gallons{};
	double miles_per_gallon{};
	
	cout << "Enter the miles: ";
	cin >> miles;
	cout << "Enter the gallons: ";
	cin >> gallons;
	
	try {
		miles_per_gallon = calculate_mpg(miles, gallons);
		cout << "Result: " << miles_per_gallon << endl;
	}
	catch(const DivideByZeroEception& ex){
		cout << "Tried to divide by zero\n";
	}
	catch(const NegativeValueException& ex){
		cout << "One of your paramaters is negative" << "\n";
	}
	catch(...){
		cout << "Unknown Exception\n";
	}
	
	cout << "Bye";
	*/
	
	Account janitAccount{2000.00, "Janit"};
	cout << janitAccount;
	
	janitAccount.deposit(500.00);
	cout << janitAccount;
	
	janitAccount.withdraw(250.00);
	cout << janitAccount;
	
	LINEBREAK;
	try
	{
		Account jimAccount{1000.0, "Jim"};
		cout << jimAccount;
		
		jimAccount.withdraw(2500.00);
		cout << janitAccount;
	}
	catch(const IllegalBalanceException& ex)
	{
		cout << "Balance cannot be less than zero" << endl;
	}
	catch(const InsufficientFundsException& ex)
	{
		cout << ex.what() << endl;
	}
	
	return 0;
}











