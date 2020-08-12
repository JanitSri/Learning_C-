/*
Container Elements
- a copy of the element will be stored in the container
- element should be:
	- copyable and assignable (copy constructor/copy assignment)
	- movable for efficency (move constructor/move assignment)
- order associative containers must be able to compare elements 
	- operator<, operator==
- most containers class can be traveresed with iterators
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <list>
#include <cctype>

#define LINEBREAK std::cout << std::endl


struct Square_Functor{
	void operator()(int x){ // overload () operator 
		std::cout << x*x << " ";
	}
};

class Person{
	friend std::ostream& operator<<(std::ostream& os, const Person& p){
		std::cout << "Name:" << p.name << " Age:" << p.age;  
		return os;
	}
private:
	std::string name;
	int age;
public:
	Person(std::string name, int age)
		:name{name}, age{age}{}
	Person()
		:Person{"Janit",27}{}
	bool operator<(const Person& rhs) const {
		return this->age < rhs.age;
	}
	bool operator==(const Person& rhs) const {
		return (this->age == rhs.age && this->name == rhs.name);
	}
};

void square_num(int x){
	std::cout << x*x << " ";
}

void stl_lib(){
	std::vector<int> vec{1,2,3};
	auto it = vec.begin();
	
	std::cout << "Vector Iterator: ";
	while(it != vec.end()){
		std::cout << *it << " ";
		it++;
	}
	
	LINEBREAK;
	std::set<char> suits{'H','C','S','D'};
	auto it_set_reverse = suits.rbegin();
	
	std::cout << "Reverse Set Iterator: ";
	while(it_set_reverse != suits.rend()){
		std::cout << *it_set_reverse << " ";
		it_set_reverse++;
	}
	
	LINEBREAK;
	LINEBREAK;
	
	std::cout << "*****STL AlGORITHMS*****" << std::endl;
	
	// 'find' returns a iterator pointing to the located element or end(), for 
	// custom data types need to overload the '==' operator 
	// 'distance' calculates the number of elements between the first and last 
	std::cout << "Using 'find' and 'distance': ";
	auto loc = std::find(vec.begin(), vec.end(), 3); // returns a pointer to the location of the element 
	if(loc != vec.end()){
		std::cout << "Found" << *loc << " at " << std::distance(vec.begin(), loc) << std::endl;
	}
	
	// 'for_each' applies a function to each element in the iterator sequence
	// function must be provided to the algorithm as functor, function pointer, lambda expression 
	std::cout << "Using a functor with 'for_each': ";
	Square_Functor square;
	std::for_each(vec.begin(),vec.end(),square);
	LINEBREAK;
	
	std::cout << "Using a function pointer with 'for_each': ";
	std::for_each(vec.begin(),vec.end(),square_num);
	LINEBREAK;
	
	std::cout << "Using a lambda function with 'for_each': ";
	std::for_each(vec.begin(),vec.end(),
		[](int x){std::cout << x*x << " ";});
	LINEBREAK;
	
	
	std::cout << "Using custom Person object with list: ";
	std::list<Person> players{
		{"Larry",18},
		{"Moe",20},
		{"Curly",21}
	};
	
	auto player_loc = std::find(players.begin(), players.end(), Person{"Larry", 18});
	if(player_loc != players.end()){
		std::cout << "Found -> " << *player_loc << " at location " << std::distance(players.begin(), player_loc) << std::endl;
	}
	else{
		std::cout << "Player does not exist" << std::endl;
	}
	
	std::cout << "Using transform with toupper(): ";
	std::string test{"This is a test"};
	std::cout << "Before transform: " << test;
	
	std::transform(test.begin(),test.end(),test.begin(), ::toupper);
	std::cout << " --- After transform: " << test << std::endl;	
}


































