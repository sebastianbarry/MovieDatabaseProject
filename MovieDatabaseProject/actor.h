#pragma once
#include <string>

using namespace std;

class actor {
private:
	int _year;
	string _award, _name, _film;
	bool _winner;

public:
	int getYear();
	void setYear(int);
	string getAward();
	void setAward(string);
	bool getWinner();
	void setWinner(bool);
	string getName();
	void setName(string);
	string getFilm();
	void setFilm(string);

	actor();
	actor(int year, string award, bool winner, string name, string film);
};