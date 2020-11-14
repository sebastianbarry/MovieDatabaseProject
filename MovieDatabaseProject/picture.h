#include <string>

using namespace std;

class picture {
public:
	string getName();
	void setName(string);
	int getYear();
	void setYear(int);
	int getNominations();
	void setNominations(int);
	double getRating();
	void setRating(double);
	int getDuration();
	void setDuration(int);
	string getGenre1();
	void setGenre1(string);
	string getGenre2();
	void setGenre2(string);
	string getRelease();
	void setRelease(string);
	int getMetacritic();
	void setMetacritic(int);
	string getSynopsis();
	void setSynopsis(string);

	picture();
    picture(string , int , int , double , int , string , string , string , int , string);

private:
	string _name, _genre1, _genre2, _release,  _synopsis;
	int _year, _nominations, _duration, _metacritic;
	double _rating;
};