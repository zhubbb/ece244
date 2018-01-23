/*
 * File:   main.cpp
 * Author: zhang823
 *
 * Created on September 22, 2014, 6:16 PM
 */

/*
 * File:   StringStreamExample.cpp
 * Author: Tarek Abdelrahman
 *
 * Created on September 25, 2012, 12:16 PM
 * Updated on September 17, 2014, 11:37 AM
 */

#include <iostream>
#include <sstream>
//global
int maxNodeNumber=0, maxResistors=0;
using namespace std;

/*
 * This program reads input one line at a time.
 * Each line has a sequence of integers, but the
 * number of integers per line is not known in advance.
 * Similarly, the number of lines is not known in advance.
 */
int main() {

    // This is the string that will hold the input line
    string line;

    // This is the integer that is read in an input line
    int readInteger;

    // This is a boolean variable that indicates if there are more lines to be read
    bool moreLines = true;

    // Get a line from the input stream

    getline(cin, line);

    // getline always succeeds, so there is no need to check for the fail flag, only the eof one
    // If getline receives a line with just the EOF it sets the eof flag in cin
    if (cin.eof()) {
       moreLines = false;
       cout << "getline received only an EOF, no lines ..." << endl;
    }
    else {
       // Print the line read from the input
       cout << "Got the following line from the input: " << line << endl;
       moreLines = true; // Not really necessary, but here for clarity
    }

    // Repeat so long as there are lines; i.e., the line does not start witm an EOF
    while (moreLines) {

        // Convert the string into a string stream called linestream
        stringstream myOwnStringStream(line);

        cout << "Converted the line into a stringstream!" << endl;

        // Read the an integer from myOwnStringStream, checking for errors.
        // This is pretty much the same as the process for checking for
        // errors when using cin. The behaviour of the flags, fail, eof,
        // etc. is pretty much the same for myOwnStringStream as for cin.
        bool moreIntegers = true;

        while (moreIntegers) {
            cout << "  Reading an integer from the stringstream" << endl;
            myOwnStringStream >> readInteger;

            if (myOwnStringStream.fail()) {
                cout << "    The read has failed :-(" << endl;
                if (myOwnStringStream.eof()) {
                    // We have read the eof of the stream, done with the line
                    cout << "       It failed because we got EOF ..." << endl;
                    cout << "       No more integers on line, moving on to next line ..." << endl;
                }
                else {
                    // Bad line, no need to ignore or clear falgs. We dispose of line
                    // and rebuild the stream from a new line read at the bottom of the
                    // loop and rebuild at the top
                    cout << "       Bad integers in input, skipping line ..." << endl;
                }
                // If an error occurs or we reach eof, stop reading integers on the line
                // but read more lines
                moreIntegers = false;
            }
            else {
                // Inptut is good, process the integer value, here we just print it
                cout << "    Integer value is: " << readInteger << endl;
            }
        }

        // We are done with a line. Since we stopped either because we reached eof
        // or because there was an error in the input, the fail flag is raised.
        // Thus, we clear the linestream flags
        myOwnStringStream.clear();
        cin.clear();

        // Get a new line
        getline(cin, line);

        if (cin.eof()) {
            moreLines = false;
            cout << "getline received only an EOF, no more lines ..." << endl;
        }
        else {
           // Print the line read from the input
           cout << "Got the following line from the input: " << line << endl;
           moreLines = true; // Not really necessary, but here for clarity
        }
    }
    cout << "We are done ... " << endl;
    return 0;
}

