#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#define LINEBREAK std::cout << std::endl

void read_from_file(){
	// 'ifstream' is only for reading in files
	// can also use 'fstream'
	
	std::ifstream in_file{"../test.txt", std::ios::in}; 
	// can use in_file.open(filename) if just declaring first 
	
	std::string str_line;
	double dbl_line;
	int int_line;
	
	if(!in_file){
		std::cerr << "Problem opening file." << std::endl;
		std::exit(1);
	}
	
	std::cout << "Content from file:\n";
	while(in_file >> str_line >> int_line >> dbl_line){ // can also use '!in_file.eof()'
		std::cout << str_line << " " << int_line << " " << dbl_line << std::endl;		
	}
	
	in_file.close();
	
	
	
	LINEBREAK;
	std::ifstream in_file2;
	
	std::string filename;
	std::cout << "Enter the name of the file:";
	std::cin >> filename;
	
	in_file2.open("../"+filename);
	
	if(!in_file2){
		std::cerr << "Problem opening file" << std::endl;
		std::exit(1);
	}
	
	std::string line;
	
	std::cout << "Content from file:\n";
	while(std::getline(in_file2, line)){ // use 'in_file2.get(c)' to get by character
		std::cout << line << std::endl;
	}
	
	in_file2.close();
	
	
	// Section Challenge 
	LINEBREAK;
	std::ifstream grade_file{"../grade.txt", std::ios::in};
	if(!grade_file){
		std::cout << "Problem locating file" << std::endl;
		std::exit(1);
	}
	
	std::string answer_key;
	std::string student_name;
	std::string student_answer;
	
	std::getline(grade_file, answer_key);
	std::cout << "ANSWER KEY: " << answer_key << std::endl;
	
	std::cout << std::setw(15) << std::left << "Student Name" << std::setw(15) << std::right << "Total Correct" << std::endl;
	while(grade_file >> student_name >> student_answer){
		
		int total = 0;
		for(size_t i = 0; i < answer_key.length(); i++){
			if(answer_key[i] == student_answer[i]){
				total++;
			}
		}
		
		std::cout << std::setw(15) << std::left << student_name << std::setw(15) << std::right << total << std::endl;
	}
	
	grade_file.close();
}



















