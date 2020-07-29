#include <iostream>
#include "Movies.h"

#define deb(x) cout << #x << " " << x << endl
#define SPACE cout << endl

using namespace std;


int main(int argv, char *argc[]){
	Movies my_movies;
	
	my_movies.display();
	
	my_movies.add_movie("Big", "PG-13",2);
	my_movies.add_movie("Star Wars", "PG",2);
	my_movies.add_movie("Cinderella", "PG",2);
	my_movies.display();
	SPACE;
	
	my_movies.add_movie("Big", "PG-13",2);
	my_movies.display();
	SPACE;
	
	my_movies.increment_movie("Cinderella");
	my_movies.display();
	SPACE;
	
	Movies library{my_movies};
	SPACE;
	
	my_movies.increment_movie("Cinderella");
	my_movies.display();
	SPACE;
	
	return 0;
}