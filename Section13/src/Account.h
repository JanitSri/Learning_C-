#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

// header file - contains the specification for the class 

// by default, class members are private and struct members are public 
class Account{ 
private:
    std::string name;
    double balance;
	static int accounts_active;
	
public:
	// can add default parameters to the constructors to reduce the amount of overloaded constructors 
	Account();
    Account(std::string name, double balance);
    Account(std::string name);
    Account(double balance);
	Account(const Account &source); // copy constructor 
	
	
    static int get_active_accounts();
	void set_balance(double b);
    double get_balance() const; // const method allows to be used with const objects
	
    void set_name(std::string n);
    std::string get_name() const; // const method allows to be used with const objects
    
    bool deposit(double amount);
    bool withdraw(double amount);
	bool check_accounts(const Account &other);
    
    ~Account(); // destructor 
    
};

#endif 
