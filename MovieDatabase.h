#include "Movie.h"
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <iostream>

class MovieDatabase {
	// attribute containing vector collection of movie objects
	// read data in from file
	// overloaded I/O operators for reading the data from file and displaying the database/answering
	// database queries
private:
	std::vector<Movie> movieCollection;
public:
	MovieDatabase();
	std::vector<Movie> getMovieCollection() const;
	void initDb();
	friend std::ostream& operator<<(std::ostream& os, const MovieDatabase& db);
};