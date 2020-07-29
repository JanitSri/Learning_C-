#include <iostream>

#define deb(x) cout << #x << " " << x << endl
#define LINEBREAK cout << endl

using namespace std;


/*
-'virtual' keyword allows for dynamic binding rather than the default of static binding 
-'virtual' is used with inhertience 
- class with virtual functions must have a virtual desctructor
-'override' keyword can be used to ensure the same method signature
-'final' is used at the class level prevents inhertience   
-'final' is used at the method level prevents further overriding 
- pure virtual functions are denoted with "=0"
- if a class has a pure virtual function it is abstract and cannot be instantiated 
- abstract class can have concreate methods as well 
- an interface has only pure virtual functions    
*/



class I_Printable{ // Interface
	friend std::ostream& operator<<(std::ostream& out, const I_Printable& obj);
	
	public:
		virtual void print(std::ostream &os) const = 0;
};

std::ostream& operator<<(std::ostream& out, const I_Printable& obj){
	obj.print(out);
	return out;
}

class Base: public I_Printable{
public:
	virtual void call(){
		cout << "Called from the Base class" << endl;
	}
	
	virtual void print(std::ostream& os) const override{
		os << "Printable Interface from the Base Class" << endl;
	} 
	
	virtual ~Base() = default;
};


class Derived: public Base{
public:
	virtual void call() override{
		cout << "Called from the Derived class" << endl;
	}
	
	virtual void print(std::ostream& os) const override{
		os << "Printable Interface from the Dervied Class" << endl;
	}
	
	virtual ~Derived() = default;
};


int main(int argv, char* argc[]){
	
	Base* b = new Base();
	Base* d = new Derived();
	
	b->call();
	d->call();
	
	cout << *b;
	cout << *d;
	
	delete b;
	delete d;
	
	return 0;
}