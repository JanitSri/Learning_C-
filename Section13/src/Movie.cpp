#include "Movie.h"

Movie::Movie(std::string name,std::string movie_rating,int times_watched)
	: name{name}, movie_rating{movie_rating}, times_watched{times_watched}{}

std::string Movie::get_name() const{
	return name; 
}


std::string Movie::get_movie_rating() const{
	return movie_rating;
}

int Movie::get_times_watched() const{
	return times_watched;
}

void Movie::increment_watched(){
	times_watched++;
}
