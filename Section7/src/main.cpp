#include <iostream>
#include <vector> 

using namespace std;

int main(int argc, char *argv[]){
	
	/*
	char vowels[] {'a','e','i','o','u'};
	cout << "First element is " << vowels[0] << endl;
	cout << "Last element is " << vowels[sizeof(vowels) - 1] << endl;
	
	int multiDimensionalArray[5][5];
	
	cout << "First Element is " << multiDimensionalArray[0][0] << endl;	
	cout << "Last Element is " << multiDimensionalArray[sizeof(multiDimensionalArray)-1][sizeof(multiDimensionalArray)-1] << endl;	
	
	
	vector<int> grades; 
	
	grades.push_back(95);
	grades.push_back(99);
	
	cout << "First Element is " << grades.at(0) << endl;	
	cout << "Last Element is " << grades.at(grades.size()-1) << endl;	
	*/ 
	
	vector<int> vector1;
	vector<int> vector2;
	
	vector1.push_back(10);
	vector1.push_back(20);
	
	vector2.push_back(100);
	vector2.push_back(200);
	
	vector <vector<int>> vector_2d;
	
	vector_2d.push_back(vector1);
	vector_2d.push_back(vector2);
	
	cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
	cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;
	
	
	
	return 0;
}
