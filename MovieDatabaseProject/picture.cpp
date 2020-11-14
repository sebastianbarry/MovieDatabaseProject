#include <string>

#include "picture.h"

using namespace std;

string picture::getName() { return _name; }
void picture::setName(string name) { _name = name; }
int picture::getYear() { return _year; }
void picture::setYear(int year) { _year = year; }
int picture::getNominations() { return _nominations; }
void picture::setNominations(int nominations) { _nominations = nominations; }
double picture::getRating() { return _rating; }
void picture::setRating(double rating) { _rating = rating; }
int picture::getDuration() { return _duration; }
void picture::setDuration(int duration) { _duration = duration; }
string picture::getGenre1() { return _genre1; }
void picture::setGenre1(string genre1) { _genre1 = genre1; }
string picture::getGenre2() { return _genre2; }
void picture::setGenre2(string genre2) { _genre2 = genre2; }
string picture::getRelease() { return _release; }
void picture::setRelease(string release) { _release = release; }
int picture::getMetacritic() { return _metacritic; }
void picture::setMetacritic(int metacritic) { _metacritic = metacritic; }
string picture::getSynopsis() { return _synopsis; }
void picture::setSynopsis(string synopsis) { _synopsis = synopsis; }

picture::picture() {
	_name = "";
	_year = 0;
	_nominations = 0;
	_rating = 0.0;
	_duration = 0;
	_genre1 = "";
	_genre2 = "";
	_release = "";
	_metacritic = 0;
	_synopsis = "";
}

picture::picture(string name, int year, int nominations, double rating, int duration, string genre1, string genre2, string release, int metacritic, string synopsis) {
	_name = name;
	_year = year;
	_nominations = nominations;
	_rating = rating;
	_duration = duration;
	_genre1 = genre1;
	_genre2 = genre2;
	_release = release;
	_metacritic = metacritic;
	_synopsis = synopsis;
}
