#pragma once 
#include <string>

class Movie{
	private:
		std::string name;
		std::string movie_rating;
		int times_watched;
	
	public:
		Movie(std::string name, std::string movie_rating, int times_watched);
		
		std::string get_name() const;
		std::string get_movie_rating() const;
		int get_times_watched() const;
		void increment_watched();
		
}; 