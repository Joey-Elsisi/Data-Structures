/*
 * Filename: ListNode.h
 * Description: ListNode class definition
  Joseph Elsisi
 jre3wjh
 September 9
 */

#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std;

class ListNode {
public:
    ListNode();                 // Constructor
    // ~ListNode();

private:
    int value;
    ListNode *next, *previous;	// for doubly linked lists

    // List needs to be able to access/change ListNode's next and
    // previous pointers
    friend class Stack;
};

#endif