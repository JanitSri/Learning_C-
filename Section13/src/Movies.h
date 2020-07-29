#pragma once 
#include <vector> 
#include <string> 
#include "Movie.h"

class Movies{
	private:
		std::vector<Movie> movie_library;
		
	public:
		bool add_movie(std::string name, std::string movie_rating, int times_watched=0);
		bool increment_watched(std::string name);
		void display() const;
};