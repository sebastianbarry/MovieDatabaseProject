#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "actor.h"
#include "picture.h"

using namespace std;

void readFileToActor(ifstream& file, vector<actor>& actorList) {



}

void readFileToPicture(ifstream& file, vector<picture>& pictureList) {


    

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

void exploreDatabase() {

}

int main()
{
    ifstream actorFile("actor-actress.csv");
    ifstream pictureFile("pictures.csv");

    vector<actor> actorList;
    vector<picture> pictureList;

    readFileToActor(actorFile, actorList);
    readFileToPicture(pictureFile, pictureList);


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
                        displayDatabase(actorList);
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
                    case 'x':
                        break;
                    default:
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
