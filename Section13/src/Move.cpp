#include <iostream>
#include "Move.h"

Move::Move(int d){
	data = new int;
	*data = d;
}

Move::Move() // delagating the constructor 
	: Move{10}{}

Move::Move(const Move &source) // deep copy constructor 
	: Move{*source.data}{ 
	std::cout << "Deep Copy Constructor Called" << std::endl;
}

Move::Move(Move &&source) // move constructor 
	: data{source.data}{
	source.data = nullptr;
	std::cout << "Move Constructor Called" << std::endl;
}

Move::~Move(){
	delete data;
	std::cout << "Destructor Called" << std::endl;
}

void Move::set_data_value(int d){
	*data = d;
}

int Move::get_data_value(){
	return *data;
}