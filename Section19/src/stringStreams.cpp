#include <iostream>
#include <string>
#include <sstream>

#define LINEBREAK std::cout << std::endl


// can use stringstream, istringstream, ostringstream 
// stringstream is connected to a std::string 

void string_stream(){
	int n;
	double d; 
	std::string s; 
	std::string info{"5 56.65 James"};
	
	std::istringstream iss{info}; 
	iss >> n >> d >> s;
	
	std::cout << "Readin from stream " << n << " " << d << " " << s << std::endl;
	
	int n2{2};
	double d2{59.44}; 
	std::string s2{"Jimmy"}; 
	
	std::ostringstream oss{};
	
	oss << n2 << " " << s2 << " " << d2;
	std::cout << "Out to stream: " << oss.str() << std::endl;
	
	
	int int_val{};
	std::string val{};
	
	std::cout << "Enter a number:";
	std::cin >> val;
	
	std::istringstream validator{val};
	
	if(validator >> int_val){
		std::cout << val << " is a number" << std::endl;
	}
	else{
		std::cout << val << " is not a number" << std::endl;
	}
}











  