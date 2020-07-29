#pragma once 
#include <vector>
#include "Movie.h"

class Movies{
	private:
		std::vector<Movie>* movies; // raw pointer 
	public:
		Movies(); // deep copy constructor
		Movies(const Movies& source); // constructor 
		Movies(Movies&& source); // move constructor 
		~Movies(); // destructor
		bool add_movie(std::string name, std::string rating, int watched);
		bool increment_movie(std::string name);
		void display() const;
};
