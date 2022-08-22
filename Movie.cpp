#include "Movie.h"

//accessor methods
std::string Movie::getTitle() const {
    return title;
}

enum Movie::ageCert Movie::strToAgeCert(const std::string& str) {
    // initializer list
    // create an unordered map of the strings to their equivalent ageCert enum.
    std::unordered_map<std::string, ageCert> eToStr = {
            {"PG-13",     PG_13},
            {"PG",        PG},
            {"R",         R},
            {"NOT RATED", NOT_RATED},
            {"G",         G},
            {"TV-14",     TV_14},
            {"APPROVED",  APPROVED},
            {"UNRATED",UNRATED}
    };
    return eToStr[str];
}

// constructor
Movie::Movie(std::string inpTitle, int inpReleaseYear, std::string inpCertStr, std::string inpGenre, int inpRuntime, int inpRating) {
    title = inpTitle;
    releaseYear = inpReleaseYear;
    movieCert = strToAgeCert(inpCertStr);
    genre = inpGenre;
    runtime = inpRuntime;
    rating = inpRating;
}



int Movie::getReleaseYear()const {
    return releaseYear;
}
std::string Movie::getGenre() const {
    return genre;
}
int Movie::getRuntime() const {
    return runtime;
}
int Movie::getRating() const {
    return rating;
}
enum Movie::ageCert Movie::getAgeCert() const {
    return movieCert;
}
std::string Movie::ageCertIndexToString(int i) {
    // initializer list: create an unordered map of the ageCert enum indexes to
     //their equivalent strings.
    std::unordered_map<int, std::string> eToStr = {
            {0, "PG-13"},
            {1, "PG"},
            {2, "R"},
            {3, "NOT RATED"},
            {4, "G"},
            {5, "TV-14"},
            {6, "APPROVED"},
            {7, "UNRATED"}
    };
    return eToStr[i];
}

//mutator methods
void Movie::setTitle(std::string inpTitle) {
    this->title = inpTitle;
}
void Movie::setReleaseYear(int inpYear) {
    this->releaseYear = inpYear;
}
void Movie::setGenre(const std::string& inpGenre) {
    this->genre = std::move(genre);
}
void Movie::setRuntime(int inpRuntime) {
    this->runtime = inpRuntime;
}
void Movie::setRating(int inpRating) {
    this->rating = inpRating;
}
void Movie::setAgeCert(const std::string& inpCertStr) {
    this->movieCert = strToAgeCert(inpCertStr);
}

//stream output method

std::ostream& operator<<(std::ostream& os, const Movie& m) {
    os << '"' << m.getTitle() << '"' << ','
        << m.getReleaseYear() << ','
        << '"' << Movie::ageCertIndexToString(m.getAgeCert()) << '"' << ','
        << '"' << m.getGenre() << '"' << ','
        << m.getRuntime() << ','
        << m.getRating() << std::endl;
    return os;
}

// stream input to constructor - parse individual line for commas

std::vector<std::string> Movie::tokenize(std::string s, std::string del)
{
    // needed to implement a custom delimiter to deal with situations where inidivual movie attributes (i.e: movie titles)
    // contain comma values
    std::vector<std::string> result;
    std::string substr;
    int strSpeechMarks = 0;
    int startSubstr = 0;
    //std::cout << "String: " << s << std::endl;
    //std::cout << s.size() << std::endl;
    int strLen = s.length();
    for (int i = 0; i < strLen; i++) {
        //std::cout << " character: " << s[i];
        if (s[i] == '"') {
            strSpeechMarks++;
            //std::cout << " num speech marks: " << strSpeechMarks << std::endl;
            //std::cout << "strSpeechMarks % 2 = " << strSpeechMarks % 2 << std::endl;
        }
        else {
            //std::cout << "" << std::endl;
        }
        if (s[i] == ',') {
            if (strSpeechMarks % 2 == 0) {
                int n = i - startSubstr;
                std::string sub = s.substr(startSubstr, n);
                result.push_back(sub);
                startSubstr = i + 1;

            }
        }
        // now need last statement t deal with end of line
        if (i == strLen-1) {
            std::string sub = s.substr(startSubstr, 1);
            result.push_back(sub);
        }
    }
    return result;
}

void Movie::setAttributesConsoleString() {
    std::string inStr;
    getline(std::cin, inStr);
    std::vector<std::string> vals = Movie::tokenize(inStr, ",");
    // for (auto i : vals) {
    //  std::cout << i << "_";}
    for (int i = 0; i < vals.size(); i++) {
        if (vals[i][0] == '"') {
            vals[i].erase(vals[i].size() - 1);
            vals[i].erase(0, 1);
        }
    }
    if (vals.size() == 6) {
        this->title = vals[0];
        this->releaseYear = std::stoi(vals[1]);
        this->rating = strToAgeCert(vals[2]);
        this->genre = vals[3];
        this->runtime = std::stoi(vals[4]);
        this->rating = std::stoi(vals[5]);

        //have to remove speech marks from strings
        //if vals[x][0] == '"' -> remove index end index and index 0
    }
}
// comparator operators

bool Movie::operator>(const Movie& m) const {
    // will be used to organise films by length
    return this->getRuntime() >= m.getRuntime();
}
bool Movie::operator<(const Movie& m) const {
    // will be used to organise films by release date.
    return this->getReleaseYear() <= m.getReleaseYear();
}
bool Movie::operator<=(const Movie& m) const {
    // will be used to compare movie objects by the length of their titles
    return this->getTitle().length() > m.getTitle().length();
}
bool Movie::compareByRelease(const Movie* m1, const Movie* m2) {
    return m1 < m2;
}
bool Movie::compareByLength(const Movie* m1, const Movie* m2) {
    return m1 > m2;
}
bool Movie::compareByTitleLength(const Movie* m1, const Movie* m2) {
    return m1 <= m2;
}