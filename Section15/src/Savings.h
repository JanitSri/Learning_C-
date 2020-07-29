#pragma once 
#include "Account.h"

class Savings: public Account{
	public:
		double int_rate;
		Savings();
		~Savings();
};