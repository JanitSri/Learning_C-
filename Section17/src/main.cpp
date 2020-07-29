#include <iostream>
#include <memory>
#include <vector>

#define LINEBREAK cout << endl;

using namespace std;

class Test{
private:
	int data;
public:
	Test(): data{0}{cout << "No-args Test Constructor" << endl;}
	Test(int data): data{data}{cout << "Args Test Constructor" << endl;}
	int get_data() const {return data;}
	~Test(){cout << "Test Destructor" << endl;}
};


class B; // forward declaration 

class A{
	shared_ptr<B> b_ptr;
public:
	void set_B(shared_ptr<B>& b){
		b_ptr = b;
	}
	A(){cout << "A Constructor" << endl;}
	~A(){cout << "A Destructor" << endl;}
}; 

class B{
	weak_ptr<A> a_ptr; // make weak pointer to break strong circular reference 
public:
	void set_A(shared_ptr<A>& a){
		a_ptr = a;
	}
	B(){cout << "B Constructor" << endl;}
	~B(){cout << "B Destructor" << endl;}
}; 


unique_ptr<vector<shared_ptr<Test>>> make(){
	return make_unique<vector<shared_ptr<Test>>>();
}

void fill(vector<shared_ptr<Test>>& vec, int num){
	for(int i = 1; i <= num; i++){
		vec.push_back(make_shared<Test>(i*10));
	}
}

void display(const vector<shared_ptr<Test>>& vec){
	for(const auto& ptr: vec){
		cout << ptr->get_data() << endl;
	}
}


int main(int argv, char* argc[]){
	/*
	Unique Pointer
		-points to an object T on the heap 
		-it is unique
		-owns what it points to 
		-cannot be assigned or copied
		-can be moved using 'std::move'
	*/
	
	unique_ptr<int> unq_ptr = make_unique<int>(100);
	/*
	-other ways to declare and intialize:
		unique_ptr<int> unq_ptr{new int{100}}; 
		unique_ptr<Account> acc_ptr = make_unique<Account>("Janit", 6000);
		auto p3 = make_unique<Player>("Hero",100,100);
	*/
	
	cout << "====================UNIQUE POINTERS====================" << endl;
	cout << *unq_ptr << endl;
	*unq_ptr = 200;
	cout << *unq_ptr << endl;
	cout << unq_ptr.get() << endl; // gets memory location 
	unq_ptr.reset(); // now it is a nullptr 
	
	
	unique_ptr<Test> t1 = make_unique<Test>(100);
	cout << t1.get() << endl;
	cout << t1->get_data() << endl;
	
	unique_ptr<Test> t2;
	t2 = move(t1);
	cout << "After moving: " << t2.get() << endl;
	
	
	/*
	Shared Pointer
		-provides shared ownership of heap objects 
		-points to an object of type T on the heap
		-it is not unique 
		-can be assigned, copied, or moved 
		-when the use count is zero, the managed object on the heap is destroyed 
	*/
	LINEBREAK;
	cout << "====================SHARED POINTERS====================" << endl;
	shared_ptr<int> shr_ptr{new int{2456}};
	cout << *shr_ptr << endl; 
	*shr_ptr = 6523;
	cout << *shr_ptr << endl; 
	cout << "Use Count: " << shr_ptr.use_count() << endl; // the number of shared_ptr objects managing the heap object 
	
	shared_ptr<int> shr_ptr2{shr_ptr};
	cout << "Use Count: " << shr_ptr.use_count() << endl; 
	
	shr_ptr.reset();
	cout << "Use Count: " << shr_ptr.use_count() << endl; 
	cout << "Use Count: " << shr_ptr2.use_count() << endl; 
	
	
	/*
	Weak Pointers 
		-
	*/
	LINEBREAK;
	cout << "====================WEAK POINTERS====================" << endl;
	/*
	Weak Pointers 
		-provides a non-owning weak reference 
		-always created from a shared_pointer
		-does not use the reference use count
		-used to prevent strong reference cycles which could prevent objects from bring detected 
	*/
	
	shared_ptr<A> a = make_shared<A>();
	shared_ptr<B> b = make_shared<B>();
	
	a->set_B(b);
	b->set_A(a);
	
	
	LINEBREAK;
	cout << "====================CUSTOM DELETER====================" << endl;
	shared_ptr<Test> test_ptr(new Test(99), [] (Test* ptr) {
		cout << "Using the custom deleter" << endl;
		delete ptr;
	});
	
	
	
	cout << "====================SECTION CHALLENGE====================" << endl;
	unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
	vec_ptr = make();
	cout << "How many many data points do you want to enter:";
	int num;
	cin >> num;
	fill(*vec_ptr, num);
	display(*vec_ptr);
	
	
	return 0;
}













