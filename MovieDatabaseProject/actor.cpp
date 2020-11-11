#include <string>

#include "actor.h"

using namespace std;

int actor::getYear() { return _year; }
void actor::setYear(int year) { _year = year; }
string actor::getAward() { return _award; }
void actor::setAward(string award) { _award = award; }
bool actor::getWinner() { return _winner; }
void actor::setWinner(bool winner) { _winner = winner; }
string actor::getName() { return _name; }
void actor::setName(string name) { _name = name; }
string actor::getFilm() { return _film; }
void actor::setFilm(string film) { _film = film; }


actor::actor() {
	_year = 0;
	_award = "";
	_winner = 0;
	_name = "";
	_film = "";
}

actor::actor(int year, string award, bool winner, string name, string film) {
	_year = year;
	_award = award;
	_winner = winner;
	_name = name;
	_film = film;
}
