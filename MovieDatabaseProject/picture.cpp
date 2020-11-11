#include <string>

#include "picture.h"

using namespace std;

string picture::getName() { return _name; }
void picture::setName(string name) { _name = name; }
string picture::getYear() { return _year; }
void picture::setYear(string year) { _year = year; }
string picture::getNominations() { return _nominations; }
void picture::setNominations(string nominations) { _nominations = nominations; }
string picture::getRating() { return _rating; }
void picture::setRating(string rating) { _rating = rating; }
string picture::getDuration() { return _duration; }
void picture::setDuration(string duration) { _duration = duration; }
string picture::getGenre1() { return _genre1; }
void picture::setGenre1(string genre1) { _genre1 = genre1; }
string picture::getGenre2() { return _genre2; }
void picture::setGenre2(string genre2) { _genre2 = genre2; }
string picture::getRelease() { return _release; }
void picture::setRelease(string release) { _release = release; }
string picture::getMetacritic() { return _metacritic; }
void picture::setMetacritic(string metacritic) { _metacritic = metacritic; }
string picture::getSynopsis() { return _synopsis; }
void picture::setSynopsis(string synopsis) { _synopsis = synopsis; }

picture::picture() {
	_name = "";
	_year = "";
	_nominations = "";
	_rating = "";
	_duration = "";
	_genre1 = "";
	_genre2 = "";
	_release = "";
	_metacritic = "";
	_synopsis = "";
}

picture::picture(string name, string year, string nominations, string rating, string duration, string genre1, string genre2, string release, string metacritic, string synopsis) {
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
