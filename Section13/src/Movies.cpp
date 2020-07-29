#include "Movies.h"
#include <vector>
#include <string>
#include <iostream>

bool Movies::add_movie(std::string name, std::string movie_rating, int times_watched){
	for(const Movie &m: movie_library){
		if(m.get_name() == name){
			return false;
		}
	}
	
	Movie temp{name, movie_rating, times_watched};
	movie_library.push_back(temp);
	return true;
}

bool Movies::increment_watched(std::string name){
	for(Movie &m: movie_library){
		if(m.get_name() == name){
			m.increment_watched();
			return true;
		}
	}
	
	return false;
}

void Movies::display() const{
	
	if(movie_library.size() == 0){
		std::cout << "No Movies in the library" << std::endl;
	}
	for(const Movie &m: movie_library){
		std::cout << "Movie Name: " << m.get_name() << " Movie Rating: " << m.get_movie_rating() << " Movie Watched: " << m.get_times_watched() << std::endl;
	}	
}