#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <windows.h>
#include <algorithm>
#include "actor.h"
#include "picture.h"

using namespace std;

void readFileToActor(ifstream& file, vector<actor>& actorList); // I prototyped these functions for neatness lol

void readFileToPicture(ifstream& file, vector<picture>& pictureList);

char getInput(char inputList[], int numberOfOptions); // also prototyped your function. These can be found at bottom of main.cpp

void addActorToDatabase(vector<actor>& actorList) {
    int tempYear;
    string tempAward, tempName, tempFilm;
    bool tempWinner;
    cout << "Enter Year:" << endl;
    cin >> tempYear;
    cout << "Enter Award:" << endl;
    cin >> tempAward;
    cout << "Enter Winner:" << endl;
    cin >> tempWinner;
    cout << "Enter Name:" << endl;
    cin >> tempName;
    cout << "Enter Film:" << endl;
    cin >> tempFilm;

    actor tempActor(tempYear, tempAward, tempWinner, tempName, tempFilm);
    actorList.push_back(tempActor);

    cout << "Record added to the Actor/Actress database!" << endl;
    cout << tempActor.getYear() << "\t" << tempActor.getAward() << "\t" << tempActor.getWinner() << "\t" << tempActor.getName() << "\t" << tempActor.getFilm() << endl;
}

void displayActorDatabase(vector<actor> actorList) {
    cout << "Year\tAward\tWinner\tName\tFilm" << endl;
    for (actor elem : actorList) {
        cout << elem.getYear() << "\t" << elem.getAward() << "\t" << elem.getWinner() << "\t" << elem.getName() << "\t" << elem.getFilm() << endl;
    }
    cout << endl;
}

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



void sortActorDatabase(vector<actor>& actorList) {
    char sortcategory, sortorder;
    char categoryInputs[] = { 'y', 'a', 'w', 'n', 'f' };
    char adInputs[] = { 'a', 'd' };
    

    cout << "What category would you like to sort by?" << endl;
    sortcategory = getInput(categoryInputs, 5);

    cout << "Ascending or descending?" << endl;
    sortorder = getInput(adInputs, 2);
    
    
    //sort(actorList.begin(), actorList.end());

    if (sortorder == 'a')
    {
        if (sortcategory == 'y')
            sort(actorList.begin(), actorList.end(), sortActorYearAscending);
        else if (sortcategory == 'a')
            sort(actorList.begin(), actorList.end(), sortActorAwardAscending);
        else if (sortcategory == 'w')
            sort(actorList.begin(), actorList.end(), sortActorWinnerAscending);
        else if (sortcategory == 'n')
            sort(actorList.begin(), actorList.end(), sortActorNameAscending);
        else if (sortcategory == 'f')
            sort(actorList.begin(), actorList.end(), sortActorFilmAscending);
    }
    else if (sortorder == 'd')
    {
        if (sortcategory == 'y')
            sort(actorList.begin(), actorList.end(), sortActorYearDescending);
        else if (sortcategory == 'a')
            sort(actorList.begin(), actorList.end(), sortActorAwardDescending);
        else if (sortcategory == 'w')
            sort(actorList.begin(), actorList.end(), sortActorWinnerDescending);
        else if (sortcategory == 'n')
            sort(actorList.begin(), actorList.end(), sortActorNameDescending);
        else if (sortcategory == 'f')
            sort(actorList.begin(), actorList.end(), sortActorFilmDescending);
    }

    cout << "Database sorted!" << endl;
}

int main()
{
    system("color a");
    //ELIAS FILE
    //ifstream actorFile(R"(C:\ClionProjects\MovieDatabaseProject\MovieDatabaseProject\actor-actress.csv)");
    //ifstream pictureFile(R"(C:\ClionProjects\MovieDatabaseProject\MovieDatabaseProject\pictures.csv)");
    //SEBASTIAN FILE
    ifstream actorFile(R"(C:\Users\sebba\source\repos\MovieDatabaseProject\MovieDatabaseProject\actor-actress.csv)");
    ifstream pictureFile(R"(C:\Users\sebba\source\repos\MovieDatabaseProject\MovieDatabaseProject\pictures.csv)");

    vector<actor> actorList; //vector for actor/actress data
    vector<picture> pictureList; // vector for picture data


    readFileToPicture(pictureFile, pictureList); // Elias needs to finnish this function


    char input;
    char dbInputs[] = { 'a', 'p' };
    char ynInputs[] = { 'y', 'n' };
    char actionInputs[] = { 'v', 's', 't', 'a', 'x' };
    do
    {
        cout << "M O V I E // D A T A B A S E\n\tTeam Samurai" << endl << endl;

        cout << "Press ENTER to enter . . ." << endl;
        cin.get();


        cout << "Which database (Actor or Pictures) would you like to access?" << endl;
        input = getInput(dbInputs, 2);
        switch (input)
        {
// ACTORS DATABASE LOOP // ACTORS DATABASE LOOP // ACTORS DATABASE LOOP // ACTORS DATABASE LOOP // ACTORS DATABASE LOOP // ACTORS DATABASE LOOP // ACTORS DATABASE LOOP 
        case 'a':
            do
            {
                readFileToActor(actorFile, actorList); // reads in actor csv when they choose to search its database
                cout << endl << "------------------\nActor/Actress Database\n------------------" << endl;

                do
                {
                    cout << "What action would you like to perform?" << endl;
                    cout << "View\tSearch\tSort\tAdd\t\t[Exit]" << endl;
                    input = getInput(actionInputs, 5);
                    switch (input)
                    {
                                                                        // VIEW ACTORS ACTION
                    case 'v':
                        displayActorDatabase(actorList);
                        break;
                                                                        // SEARCH ACTORS ACTION
                    case 's':

                        break;
                                                                        // SORT ACTORS ACTION
                    case 't':
                        sortActorDatabase(actorList);
                        break;
                                                                        // ADD ACTORS ACTION
                    case 'a':
                        cout << "Create an Actor/Actress record:" << endl;
                        addActorToDatabase(actorList);
                        break;
                                                                        // EXIT ACTORS ACTION
                    case 'x':
                        break;
                    default:
                        throw "Unexpected input";
                        break;
                    }

                    //cout << "What action would you like to perform?" << endl;
                    //cout << "View\tSearch\tSort\tAdd\t\t[Exit]" << endl;
                    //input = getinput(actionInputs, 5);
                } while (input != 'x');
                                                                        // END OF ACTORS ACTIONS 

                cout << "Would you like to return to the main menu?" << endl;
                input = getInput(ynInputs, 2);
            } while (input == 'n');
            break;
// PICTURES DATABASE LOOP // PICTURES DATABASE LOOP // PICTURES DATABASE LOOP // PICTURES DATABASE LOOP // PICTURES DATABASE LOOP // PICTURES DATABASE LOOP // PICTURES DATABASE LOOP 
        case 'p':                           
            do
            {
                cout << endl << "------------------\nPictures Database\n------------------" << endl;

                cout << "What action would you like to perform?" << endl;
                cout << "View\tSearch\tSort\tAdd\t\t[Exit]" << endl;
                input = getInput(actionInputs, 4);

                cout << "Would you like to go to the main menu?" << endl;
                input = getInput(ynInputs, 2);
            } while (input == 'n');
            break;
        default:
            throw "Unexpected input";
            break;
        }
// END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS 

        cout << "Would you like to exit the program?" << endl;
        input = getInput(ynInputs, 2);
    } while (input == 'n');

    cout << "Exiting program . . ." << endl;
    system("pause");
    return 0;
}




void readFileToPicture(ifstream& file, vector<picture>& pictureList) {   /*   *** FUNCTION GIVING STOI ERROR***
    if (file.is_open()) { //Checks if the csv file opens or not
        cout <<"\n" << "Successfully Opened The Actor/Actress CSV file!" << endl << "\n";
    } else {
        cout <<"\n" << "Error Opening Actor/Actress CSV file" << endl << "\n";
        cout << "\n" << "Please Make Sure CSV File Path Is Correct" << endl << "\n";
        exit(0);
    }
    string header, name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis;
    int records = 0;
    getline(file, header);
    while (file.good()) {
        picture pictureInstance; //picture instance is to feed into vector

        getline(file,name,',');
        pictureInstance.setName(name);

        getline(file,year,',');
        int yearConverted;
        yearConverted = stoi(year); //converts the string to int type
        pictureInstance.setYear(yearConverted);

        getline(file,nominations,',');
        int nominationsConverted;
        nominationsConverted = stoi(nominations); //converts the string to int type
        pictureInstance.setNominations(nominationsConverted);

        getline(file,rating,',');
        double ratingConverted;
        ratingConverted = stod(rating); //converts the string to int type
        pictureInstance.setRating(ratingConverted);

        getline(file,duration,',');
        int durationConverted;
        durationConverted = stoi(duration); //converts the string to int type
        pictureInstance.setDuration(durationConverted);

        getline(file,genre1,',');
        pictureInstance.setGenre1(genre1);

        getline(file,genre2,',');
        pictureInstance.setGenre2(genre2);

        getline(file,release,',');
        pictureInstance.setRelease(release);

        getline(file,metacritic,',');
        int metacriticConversion;
        metacriticConversion = stoi(metacritic); //converts the string to int type
        pictureInstance.setMetacritic(metacriticConversion);

        getline(file,synopsis,',');
        pictureInstance.setRelease(synopsis);

        pictureList.push_back(pictureInstance);
        records++;

    }
    cout << "Loading All Records" << endl;
    cout << " . . . " << endl;
    Sleep(1000);
    cout << " . . . " << endl;
    Sleep(1000);
    cout << " . . . " << endl;
    Sleep(1000);
    cout << "Records: "<< records << endl;
    cout << endl; cout << endl;

*/
}



void readFileToActor(ifstream& file, vector<actor>& actorList) {

    if (file.is_open()) { //Checks if the csv file opens or not
        cout <<"\n" << "Successfully Opened The Actor/Actress CSV file!" << endl << "\n";
    } else {
        cout <<"\n" << "Error Opening Actor/Actress CSV file" << endl << "\n";
        cout << "\n" << "Please Make Sure CSV File Path Is Correct" << endl << "\n";
        exit(0);
    }


    string header,year,award, winner, name, film; // strings that hold the value of csv contents
    int records = 0; // records iterator
    getline(file, header); // this skips the first line of the csv file
    while (file.good()) // loop until eof
    {
        actor actorInstance;  // actor instance is made to set string hold values to

        getline(file, year, ','); // gets year from csv
        int yearConverted;
        yearConverted = stoi(year); //converts the string to int type
        actorInstance.setYear(yearConverted); // sets the converted string into object instance


        getline(file,award, ','); //gets award from csv
        actorInstance.setAward(award); // sets award string into object instance


        getline(file, winner, ','); // get winner from csv
        int booleanWinner;
        booleanWinner = stoi(winner); // converts string to int type
        actorInstance.setWinner(booleanWinner); // sets converted string into object instance


        getline(file, name, ','); // reads csv file into string name
        actorInstance.setName(name); // puts that name string into object instance


        getline(file,film); // reads in film name into string
        actorInstance.setFilm(film); // sets string equal to film in the object instance

        actorList.push_back(actorInstance); // pushes this entire instance into the vector. This loops and pushes
        //all of the csv lines into the vector as actor instances


        records++;

    }

    cout << "Loading All Records" << endl;
    cout << " . . . " << endl;
    Sleep(1000);
    cout << " . . . " << endl;
    Sleep(1000);
    cout << " . . . " << endl;
    Sleep(1000);
    cout << "Records: "<< records << endl;
    cout << endl; cout << endl;



}


char getInput(char inputList[], int numberOfOptions) {			//takes in an array of different possible inputs, receives user input, tests it, and returns the index of the chosen input
    char input;
    for (int i = 0; i < numberOfOptions; i++)
    {
        cout << inputList[i];
        if (i + 1 < numberOfOptions)
            cout << " or ";
    }
    cout << " . . ." << endl;

    cin >> input;
    for (int i = 0; i < numberOfOptions; i++)
    {
        if (inputList[i] == input)
            return input;
    }
    cout << "Invalid input, please try again" << endl;	// if invalid input, try again
    return getInput(inputList, numberOfOptions);
}