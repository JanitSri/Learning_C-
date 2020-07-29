#include <iostream>
#include <string>

#define deb(x) cout << #x << " " << x << endl; 

using namespace std;


// returns a pointer to a new created array 
int *create_array(size_t size, int init_value = 0){
	int *new_array{nullptr};
	new_array = new int[size];
	
	for(size_t i{0}; i < size; i++){
		*(new_array + i) = init_value;
	}
	
	return new_array;
}

void display_storage(const int *const array, size_t size){
	for(size_t i{0}; i < size; i++){
		cout << *(array + i) << " ";
	}
	cout << endl;
}

int *apply_all(const int *const arr1, int size1, const int *const arr2, int size2){
	int *output_arr{nullptr};
	
	output_arr = new int[size1*size2];
	
	int count{0};
	for(int i{0}; i < size2; i++){
		for(int j{0}; j < size1; j++){
			output_arr[count] = *(arr1 + j) * *(arr2 + i);
			count++;
		}
	}
	
	return output_arr;
}



int main(int argc, char *argv[]){
	
	/*
	int *p{nullptr};  // pointer to an integer 
	
	cout << "Value of pointer p: " << p << endl;
	cout << "Address of pointer p: " << &p << endl;
	cout << "Sizeof of pointer p: " << sizeof p << endl;
	
	int score{97};
	int *score_ptr{nullptr};
	
	score_ptr = &score;
	
	cout << "The value of score: " << score << endl;
	cout << "The address of score: " << &score << endl;
	cout << "The address of score ponter: " << score_ptr << endl;
	
	cout << "Dereference the pointer to get the data " << *score_ptr << endl;
	
	*score_ptr = 200;
	cout << "The value of score: " << score << endl;
	
	
	int *int_ptr{nullptr};
	
	int_ptr = new int;  // creates an integer on the heap and stores the address 
	
	cout << "The address of the pointer to integer: " << int_ptr << endl;
	cout << "The data stored at the location: " << *int_ptr << endl;
	
	*int_ptr = 100;
	cout << "The data stored at the location: " << *int_ptr << endl;
	
	delete int_ptr;  // frees the allocated storage 
	
	
	int high_score{50};
	const int *high_score_ptr{&high_score}; // pointer to const, pointer can change but the data cannot change 
	cout << "high score: " << *high_score_ptr << endl;
	
	int low_score{10};
	int *const low_score_ptr{&low_score}; // const pointers, the pointer cannot change but the data can change 
	cout << "low score: " << *low_score_ptr << endl;
	
	int diff_score{1};
	const int *const diff_score_ptr{&diff_score}; // const pointer to const, the pointer or the data cannot change 
	cout << "diff score: " << *diff_score_ptr << endl;
	
	int *my_array{nullptr};
	size_t size{0};
	int init_value{0};
	
	cout << "What size is the of the array:";
	cin >> size;
	
	cout << "What is the deafult value of the array:";
	cin >> init_value;
	
	my_array = create_array(size, init_value);
	
	cout << "The newly created array: " << endl;
	display_storage(my_array, size);
	
	delete [] my_array;
	*/
	
	int array1[] {1,2,3,4,5};
	int array2[] {10,20,30};
	
	int *new_array(nullptr);
	
	
	new_array = apply_all(array1,sizeof(array1)/sizeof(*array1),array2,sizeof(array2)/sizeof(*array2));
	
	display_storage(new_array, (sizeof(array1)/sizeof(*array1))*(sizeof(array2)/sizeof(*array2)));
	
	delete [] new_array;
	
	return 0;
}












