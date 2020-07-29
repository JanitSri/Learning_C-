#include <iostream> 
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define deb(x) cout << #x << " " << x << endl;

using namespace std;

// function prototype
// only need the return type, function name and input types (parameters name is optional)
void hello(string name = "John Doe");
void pass_ref(int &num);
void pass_val(int);

int main(int argc, char *argv[]){
	
	cout << "RAND_MAX on this system is " << RAND_MAX << endl;
	srand(time(nullptr));
	
	int random_number{};
	size_t count {10};
	int min {2};
	int max {5};
	
	for(size_t i= 0; i < count; i++){
		// rand() % range_span + min value 
		random_number = rand() % max + min;
		cout << random_number << endl;
	}
	
	string name{};
	cout << "Enter your name: "; 
	cin >> name;
	hello(name);
	hello();
	
	int num{3};
	pass_val(num);
	cout << "The number is " << num << endl;
	
	pass_ref(num);
	cout << "The number is " << num << endl;
	
	return 0;
}

void hello(string name){
	cout << "Hello " << name << endl;
}

void pass_ref(int &num){
	num *= 2;
}

void pass_val(int num){
	num *= 2;
}
















