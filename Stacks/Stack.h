/*Joseph Elsisi
jre3wjh
Septeber 16
 * Filename: Stack.h
 */
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"
using namespace std;


class Stack {
public:
    Stack();//Constructor
    // Stack(const Stack& source);	//Copy Constructor
    ~Stack();			//Destructor
    // List& operator=(const List& source);	//Equals Operator
    bool isEmpty() const;		//Returns true if empty; else false
    void makeEmpty();	//Removes all items except blank head and tail
    void push(int x);	//Insert x at tail of list
    int size() const; //Returns the number of elements in the list
    void pop();
    int top();

private:
    ListNode *head, *tail;	//indicates beginning and end of the list
    int count;			//#of elements in list
};

#endif
