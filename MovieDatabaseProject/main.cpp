#ifdef _WIN32        //sleep function for windows
#include <Windows.h> // used for sleep function for windows
#else
#include <unistd.h>  // sleep function for linux
#endif

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <exception>
#include <locale>
#include "actor.h"
#include "picture.h"
#include "sortfunctions.h"

using namespace std;

void lowerCase (string& notFunAtAll);

void capitalizeStringAgain (string& notFunAtAll2);

char getInput(char inputList[], int numberOfOptions);

void readFileToActor(ifstream& file, vector<actor>& actorList);

void readFileToPicture(ifstream& file, vector<picture>& pictureList);

void displayActorDatabase(vector<actor> actorList);

void displayPictureDatabase(vector<picture> pictureList);

void searchActorDatabase(vector<actor>& actorList);

void searchPictureDatabase(vector<picture>& pictureList);

void modifyActor(vector<actor>& actorList, actor modify);

void modifyPicture(vector<picture>& pictureList, picture modify);

void sortActorDatabase(vector<actor>& actorList);

void sortPictureDatabase(vector<picture>& pictureList);

void addActorToDatabase(vector<actor>& actorList);

void addPictureToDatabase(vector<picture>& pictureList);


int main()
{
    system("color a");

    //ELIAS LENOVO LAPTOP FILE
    //ifstream actorFile(R"(C:\Users\elipe\source\repos\sebastianbarry\MovieDatabaseProject\MovieDatabaseProject\actor-actress.csv)");
    //ifstream pictureFile(R"(C:\Users\elipe\source\repos\sebastianbarry\MovieDatabaseProject\MovieDatabaseProject\pictures.csv)");
    //ELIAS FILE
    ifstream actorFile(R"(C:\ClionProjects\MovieDatabaseProject\MovieDatabaseProject\actor-actress.csv)");
    ifstream pictureFile(R"(C:\ClionProjects\MovieDatabaseProject\MovieDatabaseProject\pictures.csv)");
    //SEBASTIAN FILE
    //ifstream actorFile(R"(C:\Users\sebba\source\repos\MovieDatabaseProject\MovieDatabaseProject\actor-actress.csv)");
   // ifstream pictureFile(R"(C:\Users\sebba\source\repos\MovieDatabaseProject\MovieDatabaseProject\pictures.csv)");


    vector<actor> actorList; //vector for actor/actress data
    vector<picture> pictureList; // vector for picture data





    char input;
    char dbInputs[] = { 'a', 'p', 'x' };
    char ynInputs[] = { 'y', 'n' };
    char actionInputs[] = { 'v', 's', 't', 'a', 'x' };
    do
    {
        cout << "M O V I E // D A T A B A S E\n\tTeam Samurai" << endl << endl;

        cout << "Press ENTER to enter . . ." << endl;
        cin.get();


        cout << "Which database would you like to access?\nActors, Pictures, Exit:" << endl;
        input = getInput(dbInputs, 3);
        switch (input)
        {
            // ACTORS DATABASE LOOP // ACTORS DATABASE LOOP // ACTORS DATABASE LOOP // ACTORS DATABASE LOOP // ACTORS DATABASE LOOP // ACTORS DATABASE LOOP // ACTORS DATABASE LOOP 
        case 'a':
            readFileToActor(actorFile, actorList); // reads in actor csv when they choose to search its database
            cout << endl << "------------------\nActor/Actress Database\n------------------" << endl;

            do
            {
                cout << "What action would you like to perform?\nView, Search, Sort, Add, Exit:" << endl;
                input = getInput(actionInputs, 5);
                switch (input)
                {
                    // VIEW ACTORS ACTION
                case 'v':
                    displayActorDatabase(actorList);
                    break;
                    // SEARCH ACTORS ACTION
                case 's':
                    searchActorDatabase(actorList);
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
            } while (input != 'x');
            // END OF ACTORS ACTIONS 
            break;

            // PICTURES DATABASE LOOP // PICTURES DATABASE LOOP // PICTURES DATABASE LOOP // PICTURES DATABASE LOOP // PICTURES DATABASE LOOP // PICTURES DATABASE LOOP // PICTURES DATABASE LOOP 
        case 'p':
            readFileToPicture(pictureFile, pictureList); // reads in picture database when user choses to search it

            cout << endl << "------------------\nPictures Database\n------------------" << endl;

            do
            {
                cout << "What action would you like to perform?\nView, Search, Sort, Add, Exit:" << endl;
                input = getInput(actionInputs, 5);

                switch (input) {
                    // VIEW PICTURES ACTION
                case 'v':
                    displayPictureDatabase(pictureList);
                    break;
                    // SEARCH PICTURES ACTION
                case 's':
                    break;
                    // SORT PICTURES ACTION
                case 't':
                    break;
                    // ADD PICTURES ACTION
                case 'a':
                    cout << "Create a Picture record:" << endl;
                    addPictureToDatabase(pictureList);
                    break;
                    // EXIT PICTURES ACTION
                case 'x':
                    break;
                default:
                    throw "Unexpected input";
                    break;
                }
            } while (input != 'x');
            // END OF PICTURES ACTIONS 
            break;

        default:
            break;
        }
// END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS // END OF LOOPS 

        
        cout << "IMPLEMENT SAVE TO CSV HERE" << endl;


        cout << "Returning to the main menu . . ." << endl << endl << endl;
        Sleep(500);
        input = '-';

    } while (input != 'x');

    cout << "Exiting program . . ." << endl;
    Sleep(500);
    system("pause");
    return 0;
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

bool isNumerical(const string& str){ //function to check if string value is a number
    for(char c : str)
        if(!isdigit(c))
            return false;

    return str.empty() == false;
}

void readFileToActor(ifstream& file, vector<actor>& actorList) { // This reads CSV file into vector

    if (file.is_open()) { //Checks if the csv file opens or not
        cout << "\n" << "Successfully Opened The Actor/Actress CSV file!" << endl << "\n";
    }
    else {
        cout << "\n" << "Error Opening Actor/Actress CSV file" << endl << "\n";
        cout << "\n" << "Please Make Sure CSV File Path Is Correct" << endl << "\n";
        cout << endl;
        cerr << "Program Closing" << endl;
        cout << " . . . " << endl;
        Sleep(300);
        cout << " . . . " << endl;
        Sleep(300);
        cout << " . . . " << endl;
        Sleep(300);
        cout << endl; cout << endl;
        exit(0);
    }


    string header, year, award, winner, name, film; // strings that hold the value of csv contents
    int records = 0; // records iterator
    getline(file, header); // this skips the first line of the csv file
    while (file.good()) // loop until eof
    {
        actor actorInstance;  // actor instance is made to set string hold values to

        getline(file, year, ','); // gets year from csv

        int yearConverted;
        yearConverted = stoi(year); //converts the string to int type
        actorInstance.setYear(yearConverted); // sets the converted string into object instance


        getline(file, award, ','); //gets award from csv
        actorInstance.setAward(award); // sets award string into object instance


        getline(file, winner, ','); // get winner from csv
        int booleanWinner;
        booleanWinner = stoi(winner); // converts string to int type
        actorInstance.setWinner(booleanWinner); // sets converted string into object instance


        getline(file, name, ','); // reads csv file into string name
        actorInstance.setName(name); // puts that name string into object instance


        getline(file, film); // reads in film name into string
        actorInstance.setFilm(film); // sets string equal to film in the object instance

        actorList.push_back(actorInstance); // pushes this entire instance into the vector. This loops and pushes
        //all of the csv lines into the vector as actor instances


        records++;

    }

    cout << "Loading All Records" << endl;
    cout << " . . . " << endl;
    Sleep(300);
    cout << " . . . " << endl;
    Sleep(300);
    cout << " . . . " << endl;
    Sleep(300);
    cout << "Records: " << records << endl;
    cout << endl; cout << endl;



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
    Sleep(300);
    cout << " . . . " << endl;
    Sleep(300);
    cout << " . . . " << endl;
    Sleep(300);
    cout << "Records: "<< records << endl;
    cout << endl; cout << endl;


}

void displayActorDatabase(vector<actor> actorList) { // CHANGED TO SAY YES OR NO FOR WINNER!! CHANGED FORMATTING

    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;

    for (actor elem : actorList) {
        cout << "YEAR: " << elem.getYear() << endl;
        cout << "AWARD: " << elem.getAward() << endl;
        cout << "WINNER: ";
        if (elem.getWinner() == 1) {
            string tempWinner;
            tempWinner = "YES";
            cout << tempWinner << endl;
        }
        else {
            string tempWinner2;
            tempWinner2 = "NO";
            cout << tempWinner2 << endl;
        }
        cout << "NAME: " << elem.getName() << endl;
        cout << "FILM: " << elem.getFilm() << endl;
        cout << "--------------------------------------------------------------------------------------------------------" << endl;
        cout << "--------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;

    }
    cout << endl;
}

void displayPictureDatabase(vector<picture> pictureList) { // THIS DISPLAYS THE LAST ELEMENT IN VECTOR TWICE!!!! NEED TO FIX!!!

    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;

    for (picture elem : pictureList) {
        cout << "NAME: " << elem.getName() << endl;
        cout << "YEAR: " << elem.getYear() << endl;
        if (elem.getNominations() == 0) {
            cout << "NOMINATIONS: NONE" << endl;
        }
        else {
            cout << "NOMINATIONS: " << elem.getNominations() << endl;
        }

        cout << "RATING: " << elem.getRating() << endl;
        cout << "DURATION: " << elem.getDuration() << endl;
        cout << "GENRE1: " << elem.getGenre1() << endl;
        cout << "GENRE2: " << elem.getGenre2() << endl;
        cout << "RELEASE: " << elem.getRelease() << endl;
        if (elem.getMetacritic() == 0) {
            cout << "METACRITIC: NONE" << endl;
        }
        else {
            cout << "METACRITIC: " << elem.getMetacritic() << endl;
        }
        cout << "SYNOPSIS: " << elem.getSynopsis() << endl;
        cout << "--------------------------------------------------------------------------------------------------------" << endl;
        cout << "--------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
    }
}

void searchActorDatabase(vector<actor>& actorList) {
    char ynInputs[] = { 'y', 'n' };
    char categoryInputs[] = { 'y', 'n', 'f' };
    char input;
    vector<actor> searchedList, copyActorList;
    string searchcriteria;

    string tempStringConverter;

    for (int i = 0; i < actorList.size(); i++)
    {
        searchedList.push_back(actorList.at(i));


        tempStringConverter = searchedList[i].getName();
        lowerCase(tempStringConverter); // passed string into function that lowercases it.
        searchedList[i].setName(tempStringConverter);


        tempStringConverter = searchedList[i].getFilm();
        lowerCase(tempStringConverter); // passed string into function that lowercases it.
        searchedList[i].setFilm(tempStringConverter);


        copyActorList.push_back(actorList.at(i));
    }


    cout << "What category would you like to search by?\nYear, Name, Film:" << endl;
    input = getInput(categoryInputs, 3);
    // YEAR SEARCH
    if (input == 'y')
    {
        int yearcriteria;
        int lowestYear;
        int highestYear;


        sort(searchedList.begin(), searchedList.end(), sortActorYearAscending);
        lowestYear = searchedList.front().getYear();
        highestYear = searchedList.back().getYear();                                    //Find the bounds of the highest and lowest years for input checking later

        do
        {
            cout << "Enter a valid year . . ." << endl;
            cin >> searchcriteria;

            yearcriteria = stoi(searchcriteria);
        } while (yearcriteria < lowestYear || yearcriteria > highestYear);            //input checking

        for (int i = 0; i < searchedList.size(); i++)
        {
            if (searchedList.at(i).getYear() != yearcriteria)
            {
                searchedList.erase(searchedList.begin() + i);               //remove the item at this position if it is not within the search criteria
                i--;
            }
        }
    }
    else if (input == 'n')
    {                                                               //NAME SEARCH
        string namecriteria;


        cout << "Enter a valid name . . ." << endl;
        cin >> namecriteria;

        lowerCase(namecriteria); // changes user input to lowercase to allow us to compare

    //    transform(namecriteria.begin(), namecriteria.end(), namecriteria.begin(), tolower);

        for (int i = 0; i < searchedList.size(); i++)
        {
            string compare = searchedList.at(i).getName();

     //       transform(compare.begin(), compare.end(), compare.begin(), tolower);

            if (compare.find(namecriteria) == string::npos)
            {
                searchedList.erase(searchedList.begin() + i);               //remove the item at this position if it is not within the search criteria
                i--;
            }
        }
    }
    else if (input == 'f')
    {                                                           //FILM SEARCH
        string filmcriteria;


        cout << "Enter a valid film name . . ." << endl;
        cin >> filmcriteria;

        lowerCase(filmcriteria); // changes user input to lower case to allow us to compare

     //   transform(filmcriteria.begin(), filmcriteria.end(), filmcriteria.begin(), tolower);

        for (int i = 0; i < searchedList.size(); i++)
        {
            string compare = searchedList.at(i).getFilm();

        //    transform(compare.begin(), compare.end(), compare.begin(), tolower);

            if (compare.find(filmcriteria) == string::npos)
            {
                searchedList.erase(searchedList.begin() + i);               //remove the item at this position if it is not within the search criteria
                i--;
            }
        }
    }



    if (searchedList.size() == 0)
    {
        cout << "No actors exist with this film . . ." << endl;
        searchedList = actorList;
    }
    else if (searchedList.size() == 1)                                  //specific search activated if only one entry found
    {
        displayActorDatabase(searchedList);
        cout << "Specific search!\nWould you like to modify this entry?" << endl;
        input = getInput(ynInputs, 2);

        if (input == 'y')
        {
            modifyActor(actorList, searchedList.at(0));
        }

        searchedList = actorList;
    }
    else


        for(int i = 0; i < searchedList.size(); i++) { // this loop makes string capital again

            tempStringConverter = searchedList[i].getName();
            capitalizeStringAgain(tempStringConverter); // passed string into function that capitalized it.
            searchedList[i].setName(tempStringConverter);


            tempStringConverter = searchedList[i].getFilm();
            capitalizeStringAgain(tempStringConverter); // passed string into function that capitalized it.
            searchedList[i].setFilm(tempStringConverter);

        }
        cout << endl;
        displayActorDatabase(searchedList);                 //display searched list



    cout << "Would you like to perform another search?" << endl;
    input = getInput(ynInputs, 2);



    if (input == 'y')
    {
        if (searchedList.size() == actorList.size())
            searchActorDatabase(searchedList);
        else
        {
            cout << "Using previous search results?" << endl;
            input = getInput(ynInputs, 2);

            if (input == 'n')
                searchedList = actorList;

            searchActorDatabase(searchedList);
        }
    }
    else
        return;

}

void modifyActor(vector<actor>& actorList, actor modify) {
    char ynInputs[] = { 'y', 'n' };
    char categoryInputs[] = { 'y', 'a', 'w', 'n', 'f', 'z', 'x' };
    char input;

    int actorListIndex;

    for (int i = 0; i < actorList.size(); i++)
    {
        if (actorList.at(i).getAward() == modify.getAward() &&
            actorList.at(i).getFilm() == modify.getFilm() &&
            actorList.at(i).getName() == modify.getName() &&
            actorList.at(i).getWinner() == modify.getWinner() &&
            actorList.at(i).getYear() == modify.getYear())
            actorListIndex = i;
    }



    cout << "What category would you like to edit?\nYear, Award, Winner, Name, Film, Remove, Exit:" << endl;
    input = getInput(categoryInputs, 7);


    if (input == 'y')
    {
        string rawinput;
        int yearinput;
        int lowestYear, highestYear;

        sort(actorList.begin(), actorList.end(), sortActorYearAscending);
        lowestYear = actorList.front().getYear();
        highestYear = actorList.back().getYear();                                    //Find the bounds of the highest and lowest years for input checking later

        do
        {
            cout << "Enter a valid year . . ." << endl;
            cin >> rawinput;

            yearinput = stoi(rawinput);
        } while (yearinput < lowestYear || yearinput > highestYear);            //input checking



        actorList.at(actorListIndex).setYear(yearinput);            //edit object in the original list
    }
    else if (input == 'a')
    {

    }
    else if (input == 'w')
    {

    }
    else if (input == 'n')
    {

    }
    else if (input == 'f')
    {

    }
    else if (input == 'z')
    {
        cout << "Are you sure you would like to delete this entry?" << endl;
        input = getInput(ynInputs, 2);

        if (input == 'y')
        {
            actorList.erase(actorList.begin() + actorListIndex);
            cout << "Entry has been removed from the Actor database" << endl;
        }
        else
            modifyActor(actorList, actorList.at(actorListIndex));
        return;
    }

    vector<actor> tempForDisplay;
    tempForDisplay.push_back(actorList.at(actorListIndex));
    displayActorDatabase(actorList);                                    //display edited entry

    cout << "Would you like to edit this entry again?" << endl;
    input = getInput(ynInputs, 2);

    if (input == 'y')
        modifyActor(actorList, actorList.at(actorListIndex));
}

void sortActorDatabase(vector<actor>& actorList) {
    char sortcategory, sortorder;
    char categoryInputs[] = { 'y', 'a', 'w', 'n', 'f' };
    char adInputs[] = { 'a', 'd' };


    cout << "What category would you like to sort by?\nYear, Award, Winnder, Name, Film:" << endl;
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


    vector<actor> tempDisplay;
    tempDisplay.push_back(tempActor);

    cout << "Record added to the Actor/Actress database!" << endl;
    displayActorDatabase(tempDisplay);
}

void addPictureToDatabase(vector<picture>& pictureList) {
    int tempYear, tempNominations, tempDuration, tempMetacritic;
    string tempName, tempGenre1, tempGenre2, tempRelease, tempSynopsis;
    double tempRating;

    cout << "Enter Name:" << endl;
    
    cout << tempName;
    cout << "Enter Year:" << endl;
    cin >> tempYear;
    cout << "Enter Nominations:" << endl;
    cin >> tempNominations;
    cout << "Enter Rating:" << endl;
    cin >> tempRating;
    cout << "Enter Duration:" << endl;
    cin >> tempDuration;
    cout << "Enter Genre1:" << endl;
    cin >> tempGenre1;
    cout << "Enter Genre2:" << endl;
    cin >> tempGenre2;
    cout << "Enter Release:" << endl;
    cin >> tempRelease;
    cout << "Enter Metacritic:" << endl;
    cin >> tempMetacritic;
    cout << "Enter Synopsis:" << endl;
    cin >> tempSynopsis;

    picture tempPicture(tempName, tempYear, tempNominations, tempRating, tempDuration, tempGenre1, tempGenre2, tempRelease, tempMetacritic, tempSynopsis);
    pictureList.push_back(tempPicture);


    vector<picture> tempDisplay;
    tempDisplay.push_back(tempPicture);

    cout << "Record added to the Picture database!" << endl;
    displayPictureDatabase(tempDisplay);
}

void lowerCase (string& notFunAtAll) { // this converts strings to lower case
    for(unsigned int i = 0; i <notFunAtAll.length(); i++) {
        notFunAtAll[i] = tolower(notFunAtAll[i]); // iterates through string size and sets each index to lowercase
    }
}

void capitalizeStringAgain (string& notFunAtAll2) { // this converts the first letter of each word to capital
    for(unsigned int i = 0; i < notFunAtAll2.length(); i++) {
        if(i == 0) {
            notFunAtAll2[i] = toupper(notFunAtAll2[i]);
        }
        if(notFunAtAll2[i] == ' ') {
            notFunAtAll2[i+1] = toupper(notFunAtAll2[i+1]);
        }
    }
}