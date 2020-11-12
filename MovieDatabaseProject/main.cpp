#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <windows.h>
#include "actor.h"
#include "picture.h"

using namespace std;

void readFileToActor(ifstream& file, vector<actor>& actorList); // I prototyped these functions for neatness lol

void readFileToPicture(ifstream& file, vector<picture>& pictureList) { // Elias Still Needs to finish this function


    

}

char getinput(char inputList[], int numberOfOptions); // also prototyped your function. These can be found at bottom of main.cpp

void exploreDatabase() {

}

int main()
{
    system("color a");
    ifstream actorFile(R"(C:\ClionProjects\MovieDatabaseProject\MovieDatabaseProject\actor-actress.csv)"); // CHANGE TO FILE PATH OF YOUR COMPUTER
    ifstream pictureFile("pictures.csv"); // CHANGE TO FILE PATH OF YOUR COMPUTER

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


        cout << "Which database (Actor or Pictures) would you like to enter?" << endl;
        input = getinput(dbInputs, 2);
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
                    input = getinput(actionInputs, 4);
                    switch (input)
                    {
                                                                        // VIEW ACTORS ACTION
                    case 'v':
                      //  displayDatabase(actorList);
                        break;
                                                                        // SEARCH ACTORS ACTION
                    case 's':

                        break;
                                                                        // SORT ACTORS ACTION
                    case 't':

                        break;
                                                                        // ADD ACTORS ACTION
                    case 'a':
                        cout << "Create an Actor/Actress record:" << endl;

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
                        break;
                                                                        // EXIT ACTORS ACTION
          //         case 'x':      commented out by Elias Due to Compiling Error
                        break;
          //          default:      commented out by Elias Due to Compiling Error
                        throw "Unexpected input";
                        break;
                    }
                } while (input != 'x');
                                                                        // END OF ACTORS ACTIONS 

                cout << "Would you like to remain in the Actor Database?" << endl;
                input = getinput(ynInputs, 2);
            } while (input == 'y');
            break;
// PICTURES DATABASE LOOP // PICTURES DATABASE LOOP // PICTURES DATABASE LOOP // PICTURES DATABASE LOOP // PICTURES DATABASE LOOP // PICTURES DATABASE LOOP // PICTURES DATABASE LOOP 
        case 'p':                           
            do
            {
                cout << endl << "------------------\nPictures Database\n------------------" << endl;

                cout << "What action would you like to perform?" << endl;
                cout << "View\tSearch\tSort\tAdd\t\t[Exit]" << endl;
                input = getinput(actionInputs, 4);

                cout << "Would you like to remain in the Pictures Database?" << endl;
                input = getinput(ynInputs, 2);
            } while (input == 'y');
            break;
        default:
            throw "Unexpected input";
            break;
        }
// END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS 

        cout << "Would you like to return to the main menu?" << endl;
        input = getinput(ynInputs, 2);
    } while (input == 'y');

    cout << "Exiting program . . ." << endl;
    system("pause");
    return 0;
}





void readFileToActor(ifstream& file, vector<actor>& actorList) {

    // stringstream ss; // I was messing with streamstring
    //   string actorObjectName = "actor"; // streamstring
    if (file.is_open()) { //Checks if the csv file opens or not
        cout <<"\n" << "Successfully Opened The Actor/Actress CSV file!" << endl << "\n";
    } else {
        cout <<"\n" << "Error Opening Actor/Actress CSV file" << endl << "\n";
    }

    string header,year,award, winner, name, film; // strings that hold the value of csv contents
    int records = 0; // records iterator
    getline(file, header); // this skips the first line of the csv file
    while (file.good()) // loop until eof
    {
        //   ss << actorObjectName << records; // stream string
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
        // ss.str(""); // streamstring

    }

    cout << "Loading All Records" << endl;
    cout << " . . . " << endl;
    Sleep(1000);
    cout << " . . . " << endl;
    Sleep(1000);
    cout << " . . . " << endl;
    Sleep(1000);
    cout << "Records: "<<records << endl;
    cout << endl; cout << endl;



}


char getinput(char inputList[], int numberOfOptions) {			//takes in an array of different possible inputs, receives user input, tests it, and returns the index of the chosen input
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
    return getinput(inputList, numberOfOptions);
}