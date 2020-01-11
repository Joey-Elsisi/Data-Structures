//Used code created by Aaron Bloomfield
//Joseph ELsisi jre3wjh
//Lab 108
//Nov 25
#include <iostream>
// stdlib.h is where exit() lives
#include <stdlib.h>
// include the standard I/O library
#include <stdio.h>
#include <unordered_map>
#include "huffNode.h"
#include "heap.h"
#include <string>
using namespace std;
// we want to use parameters

void makeCodes(string arg, unordered_map<char, string> &hash_table, huffNode * n);

int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
   // attempt to open the supplied file.  FILE is a type designed to
    // hold file pointers.  The first parameter to fopen() is the
    // filename.  The second parameter is the mode -- "r" means it
    // will read from the file.
    FILE *fp = fopen(argv[1], "r");
    // if the file wasn't found, output and error message and exit
    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }
   // read in each character, one by one.  Note that the fgetc() will
    // read in a single character from a file, and returns EOF when it
    // reaches the end of a file.
    unordered_map<char, int> frequency_map;
    char g;
    while ( (g = fgetc(fp)) != EOF ){
    	if(g != '\n' && g!= '\t'){
    		frequency_map[g]++;
    	}
    }
    unordered_map<char, int>:: iterator p; 
    heap frequency_heap;
    for (p = frequency_map.begin(); p != frequency_map.end(); p++) {
    	if(p->first == '\n' || p->first == '\t'){
    		continue;
    	} else{
			// cout << "(" << p->first << ", " << p->second << ")\n";
			huffNode * temp = new huffNode(p->first, p->second);
			frequency_heap.insert(temp);
    	}
    }
    //frequency_heap.printTable();
    frequency_heap.buildHuffman();

    unordered_map<char, string> prefix_codes;

    makeCodes("", prefix_codes, frequency_heap.findMin());
    int distinct = 0;
 	unordered_map<char, string>:: iterator j; 
    for (j = prefix_codes.begin(); j != prefix_codes.end(); j++) {
    	distinct++;
    	if(j -> first == ' '){
    		cout << "space" << " " << j->second << "\n";
    	}else {
			cout << j->first << " " << j->second << "\n";
    	}
    }
    cout << "----------------------------------------" << endl;
    // rewinds the file pointer, so that it starts reading the file
    // again from the beginning
    rewind(fp);
    // read the file again, and print to the screen
    float total = 0;
    float compress = 0;
    while ( (g = fgetc(fp)) != EOF ){
       	total++;
        cout << prefix_codes[g] << " ";
        compress += prefix_codes[g].length();
    }
    total--;
    cout << endl;
    float comp_rate = (total * 8) / compress;
    float cost = float(compress) / float(total);
    cout << "----------------------------------------" << endl;
    cout << "There are a total of " << total << " symbols that are encoded." << endl;
    cout << "There are " << distinct << " ditinct symbols used." << endl;
    cout << "There were " << total * 8 << " bits in the original file." << endl;
    cout << "There were " << compress << "  bits in the compressed file." << endl;
    cout << "This gives a compression ration of " << comp_rate << " ." << endl;
    cout << "The cost of the Huffman tree is " << cost << " bits per character." << endl;
    // close the file
    fclose(fp);
    return 0;
}

void makeCodes(string arg, unordered_map<char, string> &hash_table, huffNode * n){
	if(n == NULL){
		exit(1);
	}
	if(n -> left == NULL && n -> right == NULL){
		hash_table[n->value] = arg;
	} else {
		makeCodes(arg + "0", hash_table, n -> left);
		makeCodes(arg + "1", hash_table, n -> right);
	}
} 