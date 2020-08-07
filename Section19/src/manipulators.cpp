#include <iostream>
#include <iomanip> // must be include manipulators
#include <string>

#define LINEBREAK std::cout << std::endl

void run_manipulators(){
	// Formatting Boolean 
	std::cout << "*****FORMATTING BOOLEAN*****" << std::endl;
	std::cout << (10 == 10) << std::endl;
	std::cout << (10 == 20) << std::endl;
	
	std::cout << std::boolalpha; // setting will remain until reset back to noboolalpha 
	std::cout << (10 == 10) << std::endl;
	std::cout << (10 == 20) << std::endl;
	
	std::cout << std::resetiosflags(std::ios::boolalpha); // or can use 'noboolalpha'
	std::cout << (10 == 10) << std::endl;
	
	// Formatting Integer Types 
	LINEBREAK;
	std::cout << "*****FORMATTING INTEGER*****" << std::endl;
	int num1{255};
	int num2{-255};
	
	std::cout << std::showbase << std::uppercase;
	std::cout << std::dec << num1 << std::endl;
	std::cout << std::hex << num1 << std::endl;
	std::cout << std::oct << num1 << std::endl;
	std::cout << std::resetiosflags(std::ios::basefield);
	std::cout << std::resetiosflags(std::ios::showbase);
	std::cout << std::resetiosflags(std::ios::uppercase);
	
	std::cout << std::showpos;
	std::cout << num1 << std::endl;
	std::cout << num2 << std::endl;
	
	std::cout << std::resetiosflags(std::ios::showpos);
	
	// Formatting Float Types 
	LINEBREAK;
	std::cout << "*****FORMATTING FLOAT*****" << std::endl;
	double dbl{123456789.98765431};
	std::cout << std::setprecision(9); // rounding will occur 
	std::cout << dbl << std::endl;
	
	std::cout << std::setprecision(6);
	std::cout << std::fixed; // will display precision from the decimal 
	std::cout << dbl << std::endl;
	std::cout << std::resetiosflags(std::ios::fixed);
	
	std::cout << std::setprecision(3);
	std::cout << std::scientific; 
	std::cout << dbl << std::endl;
	std::cout << std::resetiosflags(std::ios::scientific);
	
	double dbl2{12.34};
	std::cout << std::setprecision(6);
	std::cout << dbl2 << std::endl;
	std::cout << std::showpoint;
	std::cout << dbl2 << std::endl;
	std::cout << std::resetiosflags(std::ios::floatfield);
	std::cout << std::resetiosflags(std::ios::showpoint);
	
	// Aligning and Fillers 
	LINEBREAK;
	std::cout << "*****ALIGN AND FILL*****" << std::endl;
	double num{1234.5678};
	std::string hello{"Hello"};

	std::cout << num << hello << std::endl;
	std::cout << std::setw(10) << num << hello << std::endl;
	std::cout << std::setw(10) << num << std::setw(10) << hello << std::endl;
	
	std::cout << std::setw(10) << std::left << num << hello << std::endl;
	std::cout << std::setfill('=') << std::setw(10) << num << hello << std::endl;
}







































