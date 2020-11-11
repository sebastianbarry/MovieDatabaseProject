#include <string>

#include "actor.h"

using namespace std;

string actor::getYear() { return _year; }
void actor::setYear(string year) { _year = year; }
string actor::getAward() { return _award; }
void actor::setAward(string award) { _award = award; }
string actor::getWinner() { return _winner; }
void actor::setWinner(string winner) { _winner = winner; }
string actor::getName() { return _name; }
void actor::setName(string name) { _name = name; }
string actor::getFilm() { return _film; }
void actor::setFilm(string film) { _film = film; }


actor::actor() {
	_year = "";
	_award = "";
	_winner = "";
	_name = "";
	_film = "";
}

actor::actor(string year, string award, string winner, string name, string film) {
	_year = year;
	_award = award;
	_winner = winner;
	_name = name;
	_film = film;
}
