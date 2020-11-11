#include <string>

using namespace std;

class actor {
private:
	string _year, _award, _winner, _name, _film;

public:
	string getYear();
	void setYear(string);
	string getAward();
	void setAward(string);
	string getWinner();
	void setWinner(string);
	string getName();
	void setName(string);
	string getFilm();
	void setFilm(string);

	actor();
	actor(string, string, string, string, string);
};