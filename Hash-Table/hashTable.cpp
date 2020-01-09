/*
 *Joseph Elsisi
 * lab 108
 *October 20
 */


#include <vector>
#include <string>
#include <list>
#include "hashTable.h"
#include <iostream>

hashTable::hashTable(){
    table.resize(100);
    tableSize = 100;
    numValues = 0;
    powers[0] = 1;
    int placeholder = 1;
    for(int i = 1; i < 22; i++){
        placeholder *= 3;
        powers[i] = placeholder;
    }
}
hashTable::hashTable(int size){
    table.resize(getNextPrime(size));
    tableSize = size;
    numValues = 0;
    powers[0] = 1;
    int placeholder = 1;
    for(int i = 1; i < 22; i++){
        placeholder *= 3;
        powers[i] = placeholder;
    }
}
bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while (!checkprime(++n) );
    return n; // all your primes are belong to us
}
void hashTable::rehash(){
    vector<list<string>> v = table;
    int newSize = getNextPrime(tableSize * 2);
    table.resize(newSize);
    tableSize = newSize;
    for(int i = 0; i < v.size(); i++){
    list<string> curList = table[i];
    string temp;
    list<string>::iterator itr;
    int hash;
    for(itr = curList.begin(); itr != curList.end(); ++itr){
        hash = hashFunction(*itr);
        table[hash].push_front(*itr);
    }
    }
}
int hashTable::hashFunction(string value){
    unsigned long int hash = 0;
    int a = (int) value[0];
    for(int i = 0; i < value.size(); i++){
        int temp = (int) value[i];
        hash += temp * powers[i];
        //hash += temp * a;
        // a *= hash;
    }
    hash = hash % tableSize;
    return hash;
}
void hashTable::insert(string value){
    int hash = hashFunction(value);
    table[hash].push_front(value);
    numValues++;
        if((numValues/tableSize) > 0.75){
        rehash();
    }
}
hashTable::~hashTable(){}


bool hashTable::find(string value){
    int hash = hashFunction(value);
    list<string> curList = table[hash];
    string temp;
    list<string>::iterator itr;
    for(itr = curList.begin(); itr != curList.end(); ++itr){
        if(*itr == value){
            return true;
        }
    }
    return false;
}
