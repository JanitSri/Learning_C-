#include <iostream>
#include <cstring>
#include "Mystring.h"


Mystring::Mystring()
	: str{nullptr}{
	str = new char[1];
	*str = '\0';
}

Mystring::Mystring(const char* s)
	: str{nullptr}{
	if(s == nullptr){
		str = new char[1];
		*str = '\0';
	}
	else{
		str = new char[std::strlen(s)+1];
		std::strcpy(str,s);
	}
}

Mystring::Mystring(const Mystring& source)
	: str{nullptr}{
	str = new char[std::strlen(source.str)+1];
	std::strcpy(str,source.str);
	std::cout << "Copy Constructor Used" << std::endl;
}

Mystring::Mystring(Mystring&& source)
	: str{source.str}{
	source.str = nullptr;
	std::cout << "Move Constructor Used" << std::endl;
}

Mystring::~Mystring(){
	if(str == nullptr){
		std::cout << "Destructor for nullptr" << std::endl;
	}
	else{
		std::cout << "Destructor for " << str << std::endl;
	}
	delete [] str;
	
}

void Mystring::display() const{
	std::cout << str << ":" << get_length() << std::endl;
}

int Mystring::get_length() const{
	return std::strlen(str);
}

const char* Mystring::get_str() const{
	return str;
}

Mystring& Mystring::operator=(const Mystring& rhs){ // assignment operator overload (copy) 
	std::cout << "Copy Assignment Called" << std::endl;
	if(this == &rhs){
		return *this;
	}
	
	delete [] str;
	str = new char[std::strlen(rhs.str)+1];
	std::strcpy(str,rhs.str);
	return *this;
}

Mystring& Mystring::operator=(Mystring&& rhs){ // assignment operator overload (move)
	std::cout << "Move Assignment Called" << std::endl;
	if(this == &rhs){
		return *this;
	}
	
	delete [] str;
	str = rhs.str;
	rhs.str = nullptr;
	return *this;
}

Mystring Mystring::operator-() const{ // unary operator overloaded (converts to lowercase)
	char* buff = new char[std::strlen(str)+1];
	std::strcpy(buff, str);
	for(size_t i = 0; i<std::strlen(buff); i++){
		buff[i] = std::tolower(buff[i]);
	}
	Mystring temp{buff};
	delete [] buff;
	return temp;
}

std::ostream& operator<<(std::ostream& out, const Mystring& rhs){ // non-member overloaded insertion operator 
	out << rhs.str;
	return out;
}

std::istream& operator>>(std::istream& in, Mystring& rhs){ // non-member overloaded extraction operator
	char* buff = new char[1000];
	in >> buff;
	rhs = Mystring{buff};
	return in;
}

bool Mystring::operator==(const Mystring& rhs) const{
	return (std::strcmp(str,rhs.str) == 0);
}

bool Mystring::operator>(const Mystring& rhs) const{
	return (std::strcmp(str,rhs.str) > 0);
}

Mystring Mystring::operator*(int times) const{
	int buff_size = std::strlen(str) * times + 1;
	char* buff = new char[buff_size];
	
	std::strcpy(buff, "");
	for(int i=0; i < times; i++){
		std::strcat(buff, str);
	}
	
	Mystring temp{buff};
	delete [] buff;
	return temp;
}










