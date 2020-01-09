/*
 *Joseph Elsisi
 * lab 108
 *October 23
 */

//answers: big-theta = theta(n^4) because of 4 nested for loops and a linear hash table

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "timer.h"
#include "hashTable.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// Forward declarations
bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);
void fillMap(hashTable &x, string dict);
string giveDirections(int dir);
int max(int a, int b);
int main(int args, char* argv[]) {
    int count = 0;
    timer t;
    // to hold the number of rows and cols in the input file
    int rows, cols;
    // attempt to read in the file
    string dictionary(argv[1]);
    string filename(argv[2]);
    //    ifstream fileCount(dictionary);
    //    while(!fileCount.eof()) {
    //        getline(fileCount, string);
    //        int ++;
    //    }
    hashTable dictMap(50000);
    bool result = readInGrid (filename , rows, cols);
    // if there is an error, report it
    if ( !result ) {
        cout << "Error reading in file!" << endl;
        exit(1); // requires the <stdlib.h> #include header!
    }
    // Get a word (of length 10), starting at position (2,2) in the
    // array, in each of the 8 directions
    cout << endl;
    string stringFound;
    fillMap(dictMap, dictionary);
    t.start();
    string returnVal;
    for (int j = 0; j < cols; j++) { 
        for (int r = 0; r < rows; r++) {
            for (int dir = 0; dir < 8; dir++) {
                for (int len = 3; len < 23; len++) {
                   // if (!wasFound) {
                        stringFound = getWordInGrid(r, j, dir, len, rows, cols);
                        if (dictMap.find(stringFound)) {
                            returnVal += (giveDirections(dir) + " (" + to_string(r) + ", " + to_string(j) + ") :     " + stringFound + "\n");
                            //cout << giveDirections(dir) << " (" << r << ", " << j << ") :     " << stringFound << endl;
                            count++;
                        }
                }
            }
        }
    }
    //
    cout << returnVal << endl;
    cout << count << " words found"<< endl;
    t.stop();
    cout << "Found all words in " << t.getTime() <<" seconds" << endl;
    int temp = t.getTime();
    cout << temp << endl;
    return 0;
}
int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}
void fillMap(hashTable &x, string dict){
    ifstream file(dict);
    string input;
    while(file >> input){
        if(!isdigit(input[0])) {
            if(!(input.length() < 3)) {
                x.insert(input);
            }
        }
    }
}
bool readInGrid (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // grid[][] array.  In the process, we'll print the grid to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
            // cout << grid[r][c];
        }
        // cout << endl;
    }
    // return success!
    return true;
}
string giveDirections(int dir) {
    switch (dir) { // assumes grid[0][0] is in the upper-left
        case 0:
            return "N";
            break; // north
        case 1:
            return "NE";
            break; // north-east
        case 2:
            return "E";
            break; // east
        case 3:
            return "SE";
            break; // south-east
        case 4:
            return "S";
            break; // south
        case 5:
            return "SW";
            break; // south-west
        case 6:
            return "W";
            break; // west
        case 7:
            return "NW";
            break; // north-west
    }
    return NULL;
}
    char *getWordInGrid(int startRow, int startCol, int dir, int len,
                        int numRows, int numCols) {
        // the static-ness of this variable prevents it from being
        // re-declared upon each function invocataion.  It also prevents it
        // from being deallocated between invocations.  It's probably not
        // good programming practice, but it's an efficient means to return
        // a value.
        static char output[256];
        // make sure the length is not greater than the array size.
        if (len >= 255)
            len = 255;
        // the position in the output array, the current row, and the
        // current column
        int pos = 0, r = startRow, c = startCol;
        // iterate once for each character in the output
        for (int i = 0; i < len; i++) {
            // if the current row or column is out of bounds, then break
            if ((c >= numCols) || (r >= numRows) || (r < 0) || (c < 0)) {
                output[0] = ' ';
                break;
            }
            // set the next character in the output array to the next letter
            // in the grid
            output[pos++] = grid[r][c];
            // move in the direction specified by the parameter
            switch (dir) { // assumes grid[0][0] is in the upper-left
                case 0:
                    r--;
                    break; // north
                case 1:
                    r--;
                    c++;
                    break; // north-east
                case 2:
                    c++;
                    break; // east
                case 3:
                    r++;
                    c++;
                    break; // south-east
                case 4:
                    r++;
                    break; // south
                case 5:
                    r++;
                    c--;
                    break; // south-west
                case 6:
                    c--;
                    break; // west
                case 7:
                    r--;
                    c--;
                    break; // north-west
            }
        }
        // set the next character to zero (end-of-string)
        output[pos] = 0;
        // return the string (a C-style char* string, not a C++ string
        // object)
        return output;
    }

