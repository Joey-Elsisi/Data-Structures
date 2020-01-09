/*
 *Joseph Elsisi
 *Sept 8
 *jre3wjh
 ListItr.cpp
 */
#include "ListNode.h"
#include "List.h"
#include "ListItr.h"
#include <iostream>
using namespace std;

ListItr::ListItr(){}
ListItr::ListItr(ListNode *theNode){
	current = theNode;
}
bool ListItr::isPastEnd() const{
	if(current-> next == NULL){ //FIXME instead of tail
		return true;
	}
	else{
		return false;
	}
}
bool ListItr::isPastBeginning() const{
	if(current->previous == NULL){
		return true;
	}
	else{
		return false;
	}
}
void ListItr::moveForward(){
	if(this->isPastEnd() == false){
		current = current -> next;
	}
}
void ListItr::moveBackward(){
	if(this->isPastBeginning() == false){
		current = current -> previous;
	}
}
int ListItr::retrieve() const{
	return (current->value);
}