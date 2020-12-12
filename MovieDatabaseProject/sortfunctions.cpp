#include "sortfunctions.h"
#include "actor.h"
#include "picture.h"

using namespace std;


// ACTOR SORT // ACTOR SORT // ACTOR SORT // ACTOR SORT // ACTOR SORT // ACTOR SORT


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


// PICTURE SORT // PICTURE SORT // PICTURE SORT // PICTURE SORT // PICTURE SORT // PICTURE SORT



bool sortPictureNameAscending(picture lhs, picture rhs) {
    int compare = lhs.getName().compare(rhs.getName());
    if (compare < 0)
        return true;
    else
        return false;
}
bool sortPictureNameDescending(picture lhs, picture rhs){
    int compare = lhs.getName().compare(rhs.getName());
    if (compare > 0)
        return true;
    else
        return false;
}

bool sortPictureYearAscending(picture lhs, picture rhs){
    if (lhs.getYear() == rhs.getYear())
    {
        return sortPictureNameAscending(lhs, rhs);
    }
    return lhs.getYear() < rhs.getYear();
}
bool sortPictureYearDescending(picture lhs, picture rhs){
    if (lhs.getYear() == rhs.getYear())
    {
        return sortPictureNameAscending(lhs, rhs);
    }
    return lhs.getYear() > rhs.getYear();
}

bool sortPictureNominationsAscending(picture lhs, picture rhs) {
    if (lhs.getNominations() == rhs.getNominations())
    {
        return sortPictureNameAscending(lhs, rhs);
    }
    return lhs.getNominations() < rhs.getNominations();
}
bool sortPictureNominationsDescending(picture lhs, picture rhs) {
    if (lhs.getNominations() == rhs.getNominations())
    {
        return sortPictureNameAscending(lhs, rhs);
    }
    return lhs.getNominations() > rhs.getNominations();
}

bool sortPictureRatingAscending(picture lhs, picture rhs){
    if (lhs.getRating() == rhs.getRating())
    {
        return sortPictureNameAscending(lhs, rhs);
    }
    return lhs.getRating() < rhs.getRating();
}
bool sortPictureRatingDescending(picture lhs, picture rhs){
    if (lhs.getRating() == rhs.getRating())
    {
        return sortPictureNameAscending(lhs, rhs);
    }
    return lhs.getRating() > rhs.getRating();
}

bool sortPictureDurationAscending(picture lhs, picture rhs){
    if (lhs.getDuration() == rhs.getDuration())
    {
        return sortPictureNameAscending(lhs, rhs);
    }
    return lhs.getDuration() < rhs.getDuration();
}
bool sortPictureDurationDescending(picture lhs, picture rhs){
    if (lhs.getDuration() == rhs.getDuration())
    {
        return sortPictureNameAscending(lhs, rhs);
    }
    return lhs.getDuration() > rhs.getDuration();
}

bool sortPictureGenre1Ascending(picture lhs, picture rhs){
    int compare = lhs.getGenre1().compare(rhs.getGenre1());
    if (compare < 0)
        return true;
    else
        return false;
}
bool sortPictureGenre1Descending(picture lhs, picture rhs){
    int compare = lhs.getGenre1().compare(rhs.getGenre1());
    if (compare > 0)
        return true;
    else
        return false;
}

bool sortPictureGenre2Ascending(picture lhs, picture rhs){
    int compare = lhs.getGenre2().compare(rhs.getGenre2());
    if (compare < 0)
        return true;
    else
        return false;
}
bool sortPictureGenre2Descending(picture lhs, picture rhs){
    int compare = lhs.getGenre2().compare(rhs.getGenre2());
    if (compare > 0)
        return true;
    else
        return false;
}

bool sortPictureReleaseAscending(picture lhs, picture rhs){
    int compare = lhs.getRelease().compare(rhs.getRelease());
    if (compare < 0)
        return true;
    else
        return false;
}
bool sortPictureReleaseDescending(picture lhs, picture rhs){
    int compare = lhs.getRelease().compare(rhs.getRelease());
    if (compare > 0)
        return true;
    else
        return false;
}

bool sortPictureMetacriticAscending(picture lhs, picture rhs){
    if (lhs.getMetacritic() == rhs.getMetacritic())
    {
        return sortPictureNameAscending(lhs, rhs);
    }
    return lhs.getMetacritic() < rhs.getMetacritic();
}
bool sortPictureMetacriticDescending(picture lhs, picture rhs){
    if (lhs.getMetacritic() == rhs.getMetacritic())
    {
        return sortPictureNameAscending(lhs, rhs);
    }
    return lhs.getMetacritic() > rhs.getMetacritic();
}

bool sortPictureSynopsisAscending(picture lhs, picture rhs){
    int compare = lhs.getSynopsis().compare(rhs.getSynopsis());
    if (compare < 0)
        return true;
    else
        return false;
}
bool sortPictureSyonopsisDescending(picture lhs, picture rhs){
    int compare = lhs.getSynopsis().compare(rhs.getSynopsis());
    if (compare > 0)
        return true;
    else
        return false;
}