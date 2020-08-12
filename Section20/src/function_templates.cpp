#include <iostream>
#include <string>

#define LINEBREAK std::cout << std::endl

template <typename T> // can use 'class' instead of 'typename' 
T max(const T& a, const T& b){
	return (a > b) ? a : b;
}

template <typename T1, typename T2> 
void func(const T1& a, const T2& b){
	std::cout << a << " " << b << std::endl;
}

struct Person{
	std::string name;
	int age;
	
	bool operator>(const Person& rhs) const{
		return this->age > rhs.age;
	}
};

std::ostream& operator<<(std::ostream& os, const Person& p){ 
	os << "Name:" << p.name << " Age:" << p.age;
	return os;
}


void func_templates(){
	
	std::cout << "*******Function Templates*******" << std::endl;
	int a{10};
	int b{20};
	std::cout << max<int>(a,b) << std::endl;
	
	double c{56.35};
	double d{2.365};
	std::cout << max<double>(c,d) << std::endl;
	
	char e{'f'};
	char f{'F'};
	std::cout << max<char>(e,f) << std::endl;
	
	
	Person p1{"Janit",28};
	Person p2{"Jane",27};
	
	// if using a class or struct, must overload the operator 
	Person p3 = max<Person>(p1,p2);
	std::cout << p3.name << " is older." << std::endl;
	
	
	func<int, char>(5,'H');
	func<Person, char>(Person{"Jimmy",24},'A');
	
	LINEBREAK;
}













