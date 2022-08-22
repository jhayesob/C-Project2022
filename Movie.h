//
// getting back to scratch with c++
// James Hayes O'Brien - Created 19/08
//

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


class Movie {
private:
    std::string title;
    int releaseYear{};
    enum ageCert {
        PG_13, R, PG, NOT_RATED, G, TV_14, APPROVED, UNRATED
    };
    ageCert movieCert; /* set an enum variable of type ageCert called movieCert.
    * Holds the age cert of the movie */
    std::string genre;
    int runtime{};
    int rating{};
public:

    // constructor
    Movie(std::string inpTitle, int inpReleaseYear, std::string inpCertStr, std::string inpGenre, int inpRuntime, int inpRating);
    
    //accessor methods
    std::string getTitle() const;

    static ageCert strToAgeCert(const std::string& str);
    
    int getReleaseYear() const;

    std::string getGenre() const;

    int getRuntime() const;

    int getRating() const;

    ageCert getAgeCert() const;

    //mutator methods
    void setTitle(std::string inpTitle);

    void setReleaseYear(int inpYear);

    void setAgeCert(const std::string& inpCertStr);

    void setGenre(const std::string& inpGenre);

    void setRuntime(int inpRuntime);

    void setRating(int inpRating);

    // "static" meths
    static std::string ageCertIndexToString(int i);

    //stream output method

    static std::vector<std::string> tokenize(std::string s, std::string del);

    friend std::ostream& operator<<(std::ostream& os, const Movie& m);

    // friend std::istream& operator>>(std::istream& is, Movie* movieObj);

    void setAttributesConsoleString();

    // comparator operators

    bool operator>(const Movie& m) const;

    bool operator<(const Movie& m) const;

    bool operator<=(const Movie& m) const;

    // comparators
    static bool compareByRelease(const Movie* m1, const Movie* m2);
    static bool compareByLength(const Movie* m1, const Movie* m2);
    static bool compareByTitleLength(const Movie* m1, const Movie* m2);
    
    
};