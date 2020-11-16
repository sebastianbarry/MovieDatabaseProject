#include "sortfunctions.h"
#include "actor.h"

using namespace std;

bool sortActorNameAscending(actor lhs, actor rhs) {
    int compare = lhs.getName().compare(rhs.getName());
    if (compare < 0)
        return true;
    else
        return false;
}

bool sortActorNameDescending(actor lhs, actor rhs) {
    int compare = lhs.getName().compare(rhs.getName());
    if (compare > 0)
        return true;
    else
        return false;
}

bool sortActorYearAscending(actor lhs, actor rhs) {
    if (lhs.getYear() == rhs.getYear())
    {
        return sortActorNameAscending(lhs, rhs);
    }
    return lhs.getYear() < rhs.getYear();
}

bool sortActorYearDescending(actor lhs, actor rhs) {
    if (lhs.getYear() == rhs.getYear())
    {
        return sortActorNameAscending(lhs, rhs);
    }
    return lhs.getYear() > rhs.getYear();
}

bool sortActorAwardAscending(actor lhs, actor rhs) {
    int compare = lhs.getAward().compare(rhs.getAward());
    if (compare < 0)
        return true;
    else
        return false;
}

bool sortActorAwardDescending(actor lhs, actor rhs) {
    int compare = lhs.getAward().compare(rhs.getAward());
    if (compare > 0)
        return true;
    else
        return false;
}

bool sortActorWinnerAscending(actor lhs, actor rhs) {
    if (lhs.getWinner() == rhs.getWinner())
    {
        return sortActorNameAscending(lhs, rhs);
    }
    return lhs.getWinner() < rhs.getWinner();
}

bool sortActorWinnerDescending(actor lhs, actor rhs) {
    if (lhs.getWinner() == rhs.getWinner())
    {
        return sortActorNameAscending(lhs, rhs);
    }
    return lhs.getWinner() > rhs.getWinner();
}

bool sortActorFilmAscending(actor lhs, actor rhs) {
    int compare = lhs.getFilm().compare(rhs.getFilm());
    if (compare < 0)
        return true;
    else
        return false;
}

bool sortActorFilmDescending(actor lhs, actor rhs) {
    int compare = lhs.getFilm().compare(rhs.getFilm());
    if (compare > 0)
        return true;
    else
        return false;
}