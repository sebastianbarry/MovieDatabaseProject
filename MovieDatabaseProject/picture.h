#pragma once
#include <string>

using namespace std;

class picture {
private:
	int _year, _nominations, _duration, _metacritic;
	string _name, _genre1, _genre2, _release, _synopsis;
	double _rating;

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
    picture(string name, int year, int nominations, double rating, int duration, string genre1, string genre2, string release, int metacritic, string synopsis);
};