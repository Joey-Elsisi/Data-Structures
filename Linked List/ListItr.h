/*
 * Filename: ListItr.h
 * Description: ListItr class definition
 Joseph Elsisi
 jre3wjh
 September 9
 
 */
#ifndef LISTITR_H
#define LISTITR_H

#include "ListNode.h"
#include "List.h"

class ListItr {
public:
    ListItr();			//Constructor
    ListItr(ListNode* theNode);	// One parameter constructor
    bool isPastEnd() const;	//Returns true if past end position
    // in 