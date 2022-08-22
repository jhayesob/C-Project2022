#include "MovieDatabase.h"

MovieDatabase::MovieDatabase() {
	std::vector<Movie> movieCollection;
}

std::vector<Movie> MovieDatabase::getMovieCollection() const {
	return movieCollection;
}

void MovieDatabase::initDb() {
	std::ifstream ifile;
	ifile.open("films.txt");

	if (ifile.fail()) {
		std::cerr << "file failure" << std::endl;
		exit(1);
	}
	
	while (!ifile.eof()) {
		std::string inString;
		getline(ifile, inString); 

		// need to tokenise line to get line contents into a vector
		std::vector<std::string> vals = Movie::tokenize(inString, ",");
		
		for (int i = 0; i < vals.size(); i++) {
			if (vals[i][0] == '"') {
				vals[i].erase(vals[i].size() - 1);
				vals[i].erase(0, 1);
			}
			//std::cout << vals[i] << std::endl;
		}
		// for (auto i : vals) {
		//std::cout << i << ", ";}
		//std::cout << std::endl;
		
		Movie m = Movie::Movie(vals[0], std::stoi(vals[1]), vals[2], vals[3], std::stoi(vals[4]), std::stoi(vals[5]));

		//std::cout << m;
		
		// "The Good, the Bad and the Ugly" on line 4 on films.txt breaks a standard delimiter because there's a comma 
		// in the title
		this->movieCollection.push_back(m);
	}
}

std::ostream& operator<<(std::ostream& os, const MovieDatabase& db) {
	std::stringstream retVal;
	for (auto& m : db.getMovieCollection()) {
		retVal << '"' << m.getTitle() << '"' << ','
			<< m.getReleaseYear() << ','
			<< '"' << Movie::ageCertIndexToString(m.getAgeCert()) << '"' << ','
			<< '"' << m.getGenre() << '"' << ','
			<< m.getRuntime() << ','
			<< m.getRating() << std::endl;
	}
	os << retVal.str();
	return os;
}

