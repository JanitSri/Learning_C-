#pragma once

#include <vector>
#include "Account.h"
#include "Savings.h"
#include "Trust.h"
#include "Checking.h"

// Utility helper function for Account class
void display(const std::vector<Account>& accounts);
void deposit(std::vector<Account>& accounts, double amount);
void withdraw(std::vector<Account>& accounts, double amount);

// Utility helper function for Savings class
void display(const std::vector<Savings>& accounts);
void deposit(std::vector<Savings>& accounts, double amount);
void withdraw(std::vector<Savings>& accounts, double amount);


// Utility helper function for Checking class
void display(const std::vector<Checking>& accounts);
void deposit(std::vector<Checking>& accounts, double amount);
void withdraw(std::vector<Checking>& accounts, double amount);


// Utility helper function for Trust class
void display(const Trust& acc);
void deposit(Trust& acc, double amount);
void withdraw(Trust& acc, double amount);

