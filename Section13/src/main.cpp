#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
#include "Move.h"
#include "Movies.h"


#define deb(x) cout << #x << " " << x << endl

using namespace std;


void display_account_info(Account a); // function prototyping 

void increment_watched(Movies &movies, std::string name) {
    if (movies.increment_watched(name)) {
        std::cout << name << " watch incremented" <<  std::endl;
    } else {
        std::cout << name << " not found" <<  std::endl;
    }
}

void add_movie(Movies &movies, std::string name, std::string rating, int watched) {
    if (movies.add_movie(name,rating,watched)) {
        std::cout << name << " added" << std::endl;
    } else {
        std::cout << name << " already exists" <<  std::endl;
    }
}



int main(int argc, char *argv[]){
    
	/*
	Account test_account{1.00};
	
	cout << "The total active accounts are " << Account::get_active_accounts() << endl;  
	cout << "The name on the account is " << test_account.get_name() << " with an intial balance of $" << test_account.get_balance() << endl; 
	
	if(test_account.deposit(200.00))
		cout << "Deposit Confirmed." << endl;
	else
		cout << "Deposit Failed." << endl;
	
	if(test_account.withdraw(500.00))
		cout << "Withdraw Confirmed." << endl;
	else
		cout << "Insufficient Funds." << endl;
	
	if(test_account.withdraw(120000.00))
		cout << "Withdraw Confirmed." << endl;
	else
		cout << "Insufficient Funds." << endl;
	
	display_account_info(test_account);
	
	Account test_account2{};
	cout << "The total active accounts are " << Account::get_active_accounts() << endl;  
	
	display_account_info(test_account2);
	cout << "Check if the two accounts are the same: " << test_account.check_accounts(test_account2) << endl;
	
	const Account test_account3{"James", 56000.00};
	display_account_info(test_account3);
	cout << "The total active accounts are " << Account::get_active_accounts() << endl;  
	
	cout << endl;
	
	Move m{};
	Move m2{m};
	cout << "The Data in move is: " << m.get_data_value() << endl;
	cout << "The Data in move is: " << m2.get_data_value() << endl;
	
	m2.set_data_value(100);
	cout << "The Data in move is: " << m.get_data_value() << endl;
	cout << "The Data in move is: " << m2.get_data_value() << endl;
	
	vector<Move> vec;
	vec.push_back(Move());
	*/
	
	Movies my_movies;
    
    my_movies.display();
    
    add_movie(my_movies, "Big", "PG-13",2);                 // OK
    add_movie(my_movies,"Star Wars", "PG",5);             // OK
    add_movie(my_movies,"Cinderella", "PG",7);            // OK
     
    my_movies.display();   // Big, Star Wars, Cinderella
    
    add_movie(my_movies,"Cinderella", "PG",7);            // Already exists
    add_movie(my_movies,"Ice Age", "PG",12);              // OK
 
	
	return 0;
}


void display_account_info(Account a){
	cout << "Copy name: " << a.get_name() << endl;
	cout << "Copy balance: " << a.get_balance() << endl;
}









