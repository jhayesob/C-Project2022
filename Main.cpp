#include "MovieDatabase.h"

int main() {
	std::cout << "first run" << std::endl;
	Movie m = Movie("Indiana Jones and the Last Crusade", 1989, "PG-13", "Action/Adventure/Fantasy", 127, 0);
	std::cout << m << std::endl;

	// m.setAttributesConsoleString();
	// std::cout << "updated movie: " << m << std::endl;


	MovieDatabase db = MovieDatabase();
	db.initDb();
	std::cout << db << std::endl;

	// filename >> db;
	// std::cout << db;

	// display 3rd longest film of genre "film-noir"
	// display film with longest title

	return 0;
}