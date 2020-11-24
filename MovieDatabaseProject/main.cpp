#ifdef _WIN32        //sleep function for windows
#include <Windows.h> // used for sleep function for windows
#else
#include <unistd.h>  // sleep function for linux
#endif


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <exception>
#include "actor.h"
#include "picture.h"
#include "sortfunctions.h"

using namespace std;



void readFileToActor(ifstream& file, vector<actor>& actorList);

void readFileToPicture(ifstream& file, vector<picture>& pictureList);

char getInput(char inputList[], int numberOfOptions);

void addActorToDatabase(vector<actor>& actorList);

void displayActorDatabase(vector<actor> actorList);

void displayPictureDatabase(vector<picture> pictureList);

void sortActorDatabase(vector<actor>& actorList);




int main()
{
    system("color a");

    //ELIAS LENOVO LAPTOP FILE
    ifstream actorFile(R"(C:\Users\elipe\source\repos\sebastianbarry\MovieDatabaseProject\MovieDatabaseProject\actor-actress.csv)");
    ifstream pictureFile(R"(C:\Users\elipe\source\repos\sebastianbarry\MovieDatabaseProject\MovieDatabaseProject\pictures.csv)");
    //ELIAS FILE
   // ifstream actorFile(R"(C:\ClionProjects\MovieDatabaseProject\MovieDatabaseProject\actor-actress.csv)");
   // ifstream pictureFile(R"(C:\ClionProjects\MovieDatabaseProject\MovieDatabaseProject\pictures.csv)");
    //SEBASTIAN FILE
    //ifstream actorFile(R"(C:\Users\sebba\source\repos\MovieDatabaseProject\MovieDatabaseProject\actor-actress.csv)");
    //ifstream pictureFile(R"(C:\Users\sebba\source\repos\MovieDatabaseProject\MovieDatabaseProject\pictures.csv)");


    vector<actor> actorList; //vector for actor/actress data
    vector<picture> pictureList; // vector for picture data





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
                readFileToPicture(pictureFile, pictureList); // reads in picture database when user choses to search it

                cout << endl << "------------------\nPictures Database\n------------------" << endl;

                cout << "What action would you like to perform?" << endl;
                cout << "View\tSearch\tSort\tAdd\t\t[Exit]" << endl;
                input = getInput(actionInputs, 4);

                

                switch(input) {
                    case 'v':
                        displayPictureDatabase(pictureList);
                        break;
                    default:
                        throw "Unexpected input";
                        break;
                }

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


bool isNumerical(const string& str){ //function to check if string value is a number
    for(char c : str)
        if(!isdigit(c))
            return false;

    return str.empty() == false;
}


void readFileToPicture(ifstream& file, vector<picture>& pictureList) { // this reads CSV file into vector

    if (file.is_open()) { //Checks if the csv file opens or not
        cout <<"\n" << "Successfully Opened The Pictures CSV File!" << endl << "\n";
    } else {
        cout <<"\n" << "Error Opening Pictures CSV file" << endl << "\n";
        cout << "\n" << "Please Make Sure CSV File Path Is Correct" << endl << "\n";
        exit(0);
    }
    string header, name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis, line;
    int records = 0;
    getline(file, header); // gets first line

    while (file.good()) {
        picture pictureInstance; //picture instance is to feed into vector



        getline(file,line); // gets ENTIRE line

        stringstream ss(line); // place entire line into a string stream


        while(ss.good()) { // while string stream is not empty   This takes the line and seperates it by ','
            getline(ss,name,',');
            if (name.empty() || name == "-") {
                name = "NONE";
                pictureInstance.setName(name);


            }
            else {
                pictureInstance.setName(name);

            }
            getline(ss,year,',');
            if(isNumerical(year)) {
                int yearConverted = stoi(year);
                pictureInstance.setYear(yearConverted);

            } else {
                pictureInstance.setYear(0);

            }
            getline(ss,nominations,',');

            if(isNumerical(nominations)) {
                int nominationsConverted = stoi(nominations);
                pictureInstance.setNominations(nominationsConverted);
            }
            else {
                pictureInstance.setNominations(0);
            }

            getline(ss,rating,',');


                double ratingConverted = stod(rating);
                pictureInstance.setRating(ratingConverted);

            getline(ss,duration,',');
            if(isNumerical(duration)) {
                int durationConverted = stoi(duration);
                pictureInstance.setDuration(durationConverted);
            }
            else {
                pictureInstance.setDuration(0);
            }
            getline(ss,genre1,',');
            if (genre1.empty() || genre1 == "-") {
                genre1 = "NONE";
                pictureInstance.setGenre1(genre1);
            }
            else {
                pictureInstance.setGenre1(genre1);
            }
            getline(ss,genre2,',');
            if (genre2.empty() || genre2 == "-") {
                genre2 = "NONE";
                pictureInstance.setGenre2(genre2);
            }
            else {
                pictureInstance.setGenre2(genre2);
            }

            getline(ss,release,',');
            if (release.empty() || release == "-") {
                release = "NONE";
                pictureInstance.setRelease(release);
            }
            else {
                pictureInstance.setRelease(release);
            }

            getline(ss,metacritic,',');
            if(isNumerical(metacritic)) {
                int metacriticConversion = stoi(metacritic);
                pictureInstance.setMetacritic(metacriticConversion);
            }
            else {
                pictureInstance.setMetacritic(0);
            }
            getline(ss,synopsis,',');
            if (synopsis.empty() || synopsis == "-") {
                synopsis = "NONE";
                pictureInstance.setSynopsis(synopsis);
            }
            else {
                pictureInstance.setSynopsis(synopsis);

                pictureList.push_back(pictureInstance);
                records++;
            }

        }






    }

    cout << "Loading All Records" << endl;
    cout << " . . . " << endl;
    Sleep(500);
    cout << " . . . " << endl;
    Sleep(500);
    cout << " . . . " << endl;
    Sleep(500);
    cout << "Records: "<< records << endl;
    cout << endl; cout << endl;


}



void readFileToActor(ifstream& file, vector<actor>& actorList) { // This reads CSV file into vector

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
    Sleep(500);
    cout << " . . . " << endl;
    Sleep(500);
    cout << " . . . " << endl;
    Sleep(500);
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

void displayActorDatabase(vector<actor> actorList) { // CHANGED TO SAY YES OR NO FOR WINNER!! CHANGED FORMATTING
    cout << "Year\tAward\t\t\t\tWinner\t\tName\t\t\tFilm" << endl;
    for (actor elem : actorList) {
        cout << "YEAR: " << elem.getYear() << endl;
        cout << "AWARD: " << elem.getAward() << endl;
        cout << "WINNER: ";
        if(elem.getWinner() == 1){
            string tempWinner;
            tempWinner = "YES";
            cout << tempWinner << endl;
        } else {
            string tempWinner2;
            tempWinner2 = "NO";
            cout << tempWinner2 << endl;
        }
        cout << "NAME: " << elem.getName() << endl;
        cout << "FILM: " << elem.getFilm() << endl;
        cout << "--------------------------------------------------------------------------------------------------------"<<endl;
        cout << "--------------------------------------------------------------------------------------------------------"<<endl;
        cout << endl;

    }
    cout << endl;
}

void displayPictureDatabase(vector<picture> pictureList) { // THIS DISPLAYS THE LAST ELEMENT IN VECTOR TWICE!!!! NEED TO FIX!!!
   for(picture elem : pictureList) {
       cout << "NAME: " << elem.getName() << endl;
       cout << "YEAR: " << elem.getYear() << endl;
       if(elem.getNominations() == 0) {
           cout << "NOMINATIONS: NONE" << endl;
       } else {
           cout << "NOMINATIONS: " << elem.getNominations() << endl;
       }
      
       cout << "RATING: " << elem.getRating() << endl;
       cout << "DURATION: " << elem.getDuration() << endl;
       cout << "GENRE1: " << elem.getGenre1() << endl;
       cout << "GENRE2: " << elem.getGenre2() << endl;
       cout << "RELEASE: " << elem.getRelease() << endl;
       if(elem.getMetacritic() == 0) {
           cout << "METACRITIC: NONE" << endl;
       } else {
           cout << "METACRITIC: " << elem.getMetacritic() << endl;
       }
       cout << "SYNOPSIS: " << elem.getSynopsis() << endl;
       cout << "--------------------------------------------------------------------------------------------------------"<<endl;
       cout << "--------------------------------------------------------------------------------------------------------"<<endl;
       cout << endl;
   }
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