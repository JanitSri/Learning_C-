#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


#define LINEBREAK std::cout << std::endl


// fstream and ofstream are commonly used for output files

void write_to_file(){
	// 'ofstream' is only for writing to files
	// can also use 'fstream'
	
	/*
	std::ios::trunc --> truncate when opening (default)
	std::ios::app --> append on each write
	std::ios::ate --> seek to end of stream when opening 
	*/
	
	
	std::ofstream out_file{"../out_file.txt", std::ios::app};
	// can use out_file.open(filename) if just declaring first
	
	if(!out_file){
		std::cerr << "Problem writing to file" << std::endl;
		std::exit(1);
	}
	
	std::string line;
	std::cout << "Enter something to write to file:";
	
	std::getline(std::cin, line); // use 'out_file.out(c)' to write by character
	out_file << line << std::endl;
	
	out_file.close();
	
	
	// Section Challenge 
	std::ifstream infile;
	std::ofstream outfile;
	
	std::string infile_name;
	std::string outfile_name;
	
	std::cout << "Enter the input file name and outfile name seperated by space:";
	std::cin >> infile_name >> outfile_name;
	
	infile.open("../"+infile_name);
	outfile.open("../"+outfile_name, std::ios::app);
	
	if(!infile){
		std::cerr << "Error opening infile" << std::endl;
	}
	
	if(!outfile){
		std::cerr << "Error opening outfile" << std::endl;
	}
	
	std::string current_line;
	int count{1};
	while(std::getline(infile, current_line)){
		if(!current_line.empty()){
			outfile << std::setw(4) << std::left << count << current_line << std::endl; 
			count++;
		}
		else{
			outfile << std::endl;
		}
	}
	
	std::cout << "Finish copying file and adding numbered lines" << std::endl; 
	
	infile.close();
	outfile.close();
}























