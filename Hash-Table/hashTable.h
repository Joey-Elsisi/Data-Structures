/*
 *Joseph Elsisi
 * lab 108
 *October 20
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>
#include <list>

using namespace std;

class hashTable{
private:
    int hashFunction(string value);
    int numValues;
    int tableSize;
    vector <list<string>> table;
    int powers[23];
    bool checkprime(unsigned int p);
    int getNextPrime (unsigned int n);
    void rehash();

public:
    void insert(string value);
    bool find(string value);
    hashTable();
    hashTable(int size);
    ~hashTable();
};

#endif