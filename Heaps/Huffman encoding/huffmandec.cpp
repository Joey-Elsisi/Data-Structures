// This program is the skeleton code for the lab 10 in-lab.  It uses
// C++ streams for the file input, and just prints out the data when
// read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <cstddef>
// #include "heap.h"
#include "huffNode.h"
using namespace std;

// main(): we want to use parameters
int stringToInt(string s);
string findVal(string s, huffNode * c, huffNode * root, int i);
void makeTree(huffNode * c, string prefix, string character);
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // heap huffTree;
    // read in the first section of the file: the prefix codes
    huffNode * root = new huffNode('$', NULL);
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        makeTree(root, prefix, character);
        //huffNode * temp = new huffNode(character[0], stringToInt(prefix));
        //huffTree.insert(temp);
       // cout << "character '" << character << "' has prefix code '"
         //    << prefix << "'" << endl;
    }
    //huffTree.buildHuffman();
    //huffTree.printTable(huffTree.findMin(), false);

    // read in the second section of the file: the encoded message
    stringstream sstm;
    //huffNode * root = huffTree.findMin();
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        //cout << bits << endl;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
        sstm << bits;
    }
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    // string output = findVal(allbits, root, root, 0);
    string output = findVal(allbits, root, root, 0);
    cout << output << endl;
    // close the file before exiting
    file.close();
    return 0;
}
void makeTree(huffNode * c, string prefix, string character){
    int i = 0;
    while(i != prefix.length() - 1){
        if(prefix[i] == '0'){
            if(c -> left == NULL){
                c -> left = new huffNode('$', NULL);
                c = c -> left;
            } else{
                c = c -> left;
            }
        } else if(prefix[i] == '1'){
            if(c -> right == NULL){
                c -> right = new huffNode('$', NULL);
                c = c -> right;
            } else{
                c = c -> right;
            }
        }
        i++;
    } if(prefix[i] == '0'){
        c -> left = new huffNode(character[0], NULL);
    } else if(prefix[i] == '1'){
        c -> right = new huffNode(character[0], NULL);
    }
}
int stringToInt(string s){
    int ret = 0;
    for(int i = 0; i < s.length(); i++){
        ret += (int)s[i];
    }
    return ret;
}
string findVal(string s, huffNode * c, huffNode * root, int i){
    string ret;
    if(s.length() + 1 == i){
        return ret;
    }
    if(c -> left == NULL && c -> right == NULL){
        ret += c -> value;
        c = root;
    }
    if(s[i] == '0'){
        i += 1;
        ret += findVal(s, c -> left, root, i);
    } else if(s[i] == '1'){
        i += 1;
        ret += findVal(s, c -> right, root, i);
    }
    return ret;
}