#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

const int CRN = 0;
const int PREF = 1;
const int CRS = 2;
const int TITLE = 3;
const int CR = 4;
const int DAYS = 5;
const int STARTTIME = 6;
const int ENDTIME = 7;
const int ROOM = 8;
const int CAP = 9;
const int STARTDATE = 10;
const int ENDDATE = 11;
const int LASTNAME = 12;
const int FIRSTNAME = 13;
const int COURSENOTES = 14;

const int MAX = 100;
const int COLS = 15;

string master[COLS][MAX];

const string ORDER[COLS] = {"CRN", "PREF","CRS", "TITLE", "CR", "DAYS", "STARTTIME", "ENDTIME", "ROOM", "CAP", "STARTDATE", "ENDDATE", "LASTNAME", "FIRSTNAME", "COURSENOTES"};

// printMaster prints the master array out
void printMaster() {
	for (int col = 0; col < COLS; col++) {
		cout << "=====" << ORDER[col] << "=====" << endl;
		for (int row = 0; row < MAX; row++) {
			if (master[col][row] != "NONE") {
				cout << master[col][row] << endl;
			}
		}
		cout << endl << endl; // for formatting
	}
}

// convert time to military time
string toMilitary(string time) {
    // -------------Checks--------------

    // Check if TBA
    if (time == "TBA") {
        return "0";
    }

    // Check if length is correct
    if (time.length() != 6) {
        cout << "Time format is incorrect: " << time << endl;
        return "0";
    }

	//-------------Conversion-------------
    string numberstr = time.substr(0, 4); // example 0150
    string suffix = time.substr(4, 2);  // example PM

	int numbers = stoi(numberstr);

    if (suffix == "am" || suffix == "AM") {
    	if (numbers >= 1200) {
			return to_string(numbers-1200);
		} else {
			return to_string(numbers);
		}
    } else if (suffix == "pm" || suffix == "PM") {
		if (numbers >= 1200) {
			return to_string(numbers);
		} else {
			return to_string(numbers+1200);
		}
        return to_string(numbers);
    }
	cout << suffix << endl;
	return "ERROR";
}

//changed it so it is it's own separate function. LG
void initalizeArray (){
    // initialize array elements
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < MAX; j++) {
            master[i][j] = "NONE"; // Initialize with NONE so we will know if something is wrong
        }
    }

}


int main()
{
        ifstream inFile;
        ofstream outFile;
        string cell;

        initalizeArray();

        inFile.open( "/home/lili/CLionProjects/untitled1/Test.csv" );
        outFile.open( "Master Copy.txt" );

        if ( !inFile )
        {
            cout << "Unable to Open File";
        }
        while (!inFile.fail())
        {
            getline (inFile, cell, ',');   //get a group of wards seperated by commas LG
            for ( int col = 0; col < COLS; col++)
            {
                for ( int row = 0; row < MAX; row++)
                {
                    master[col][row] = cell;    //be filling array, but I don't think it is working LG
                }
            }
        }
   	 printMaster();
        inFile.close( );
        outFile.close( );




    return 0;
}
