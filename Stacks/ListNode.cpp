/*
 *Joseph Elsisi
 jre3wjh
 *Sept 8
 *ListNode.cpp
 */
#include "ListNode.h"
#include <iostream>
using namespace std;

ListNode::ListNode(){//took out the :value(0)
	value = 0;
	ListNode *next = NULL;
	ListNode *previous = NULL;
}
