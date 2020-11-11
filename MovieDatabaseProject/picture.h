#include <string>

using namespace std;

class picture {
public:
	string getName();
	void setName(string);
	string getYear();
	void setYear(string);
	string getNominations();
	void setNominations(string);
	string getRating();
	void setRating(string);
	string getDuration();
	void setDuration(string);
	string getGenre1();
	void setGenre1(string);
	string getGenre2();
	void setGenre2(string);
	string getRelease();
	void setRelease(string);
	string getMetacritic();
	void setMetacritic(string);
	string getSynopsis();
	void setSynopsis(string);

	picture();
	picture(string, string, string, string, string, string, string, string, string, string);

private:
	string _name, _year, _nominations, _rating, _duration, _genre1, _genre2, _release, _metacritic, _synopsis;
};