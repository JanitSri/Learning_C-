#pragma once 
#include <string>


class Movie{
	private:
		std::string name;
		std::string rating;
		int watched;
	public:
		Movie(std::string name, std::string rating, int watched);
		std::string get_name() const;
		std::string get_rating() const;
		int get_watched() const;
		
		void set_name(std::string name);
		void set_rating(std::string rating);
		void set_watched(int watched);
		
		void increment_watched();
};
