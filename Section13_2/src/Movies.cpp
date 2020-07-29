#include <iostream>
#include "Movies.h"

Movies::Movies(){ // constructor
	movies = new std::vector<Movie>;
	std::cout << "Constructor Called" << std::endl;
}

Movies::Movies(const Movies& source){ // deep copy constructor
	movies = new std::vector<Movie>;
	*movies = *source.movies;
	std::cout << "Deep Copy Constructor Called" << std::endl;
}

Movies::Movies(Movies&& source) // move constructor
	: movies{source.movies}{
		source.movies = nullptr;
		std::cout << "Move Constructor Called" << std::endl;
}

Movies::~Movies(){ // destructor 
	delete movies;
	std::cout << "Destructor Called" << std::endl;
}

bool Movies::add_movie(std::string name, std::string rating, int watched){
	for(const Movie& m: *movies){
		if(m.get_name() == name){
			return false;
		}
	}
	
	Movie temp{name, rating, watched};
	(*movies).push_back(temp);
	return true;
}

bool Movies::increment_movie(std::string name){
	for(Movie& m: *movies){
		if(m.get_name() == name){
			m.increment_watched();
			return true;
		}
	}
	
	return false;
}

void Movies::display() const{
	
	if((*movies).size() == 0){
		std::cout << "No Movies to Display" << std::endl;
	}
	else{
		for(const Movie &m: *movies){
			std::cout << "Movie Name: " << m.get_name() << " Movie Rating: " << m.get_rating() << " Movie Watched: " << m.get_watched() << std::endl;
		}		
	}
}