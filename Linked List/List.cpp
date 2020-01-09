/*
 *Joseph Elsisi
 *Sept 8
 *jre3wjh
 List.cpp
 */
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"
#include <iostream>

using namespace std;

List::List():count(0){
	head = new ListNode;
	tail = new ListNode;
	head -> next = tail;
	head -> previous = NULL;
	tail -> previous = head;
	tail -> next = NULL;
}
List::~List(){
	makeEmpty();
	delete this->head;
	delete this->tail;
}
List::List(const List& source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter;
    iter = ListItr(source.head->next);
    while (!(iter.isPastEnd())) {       // deep copy of the list
       	insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}
List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter;
        iter = ListItr(source.head->next); //warning
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}
ListItr List::first(){
	return ListItr(head -> next);
}
ListItr List::last(){
	return ListItr(tail -> previous);
}
void List::insertAfter(int x, ListItr position){
	ListNode *newNode = new ListNode;
	newNode -> value = x;
	newNode -> next = position.current -> next;
	newNode -> previous = position.current;
	position.current -> next = newNode;
	position.moveForward();
	position.current -> next -> previous = newNode;
	count++;//NEW ADD

}
void List::insertBefore(int x, ListItr position){
	ListNode *newNode = new ListNode;
	newNode -> value = x;
	newNode -> next = position.current;
	//position.current -> previous -> next = newNode;
	newNode -> previous = position.current -> previous;
	position.current -> previous -> next = newNode;
	position.current -> previous = newNode;
	count++;//NEW ADD
}
void List::insertAtTail(int x){
	ListNode *newNode = new ListNode;
	newNode -> value = x;
	newNode -> next = tail;
	newNode -> previous = tail -> previous;
	tail -> previous -> next = newNode;
	tail -> previous = newNode;
	count++;//NEW ADD
}
void List::remove(int x){
	ListItr deleter = first();
	// deleter.moveForward();
	while((deleter.isPastEnd()) != true){
		if((deleter.current -> value) == x){
			deleter.current -> next -> previous = deleter.current -> previous;
			deleter.current -> previous -> next = deleter.current -> next;
			// delete deleter.current -> next;
			// delete deleter.current -> previous;
			delete deleter.current;
			count--;//NEW ADD
			break;
		}
		deleter.moveForward();
	}
}
ListItr List::find(int x){
	ListItr finder = first();
	// finder.moveForward();
	while((finder.isPastEnd()) != true){
		if((finder.current -> value) == x){
			return ListItr(finder.current);
		}
		finder.moveForward();
	}
	return ListItr(tail);
}
int List::size() const{ //const problem FIXME size will be broken
	// int count = 0;
	// ListItr counter = first();
	// counter.moveForward();
	// while((counter.isPastEnd()) != true){
	// 	count++;
	// 	counter.moveForward();
	// }
	return count;
}
bool List::isEmpty() const{
	if((this-> count) == 0){
		return true;
	}
	else{
		return false;
	}
}
void List::makeEmpty(){
	ListItr deleter = first();
	while((deleter.isPastEnd()) != true){
		// ListNode *temp = deleter.current;
	deleter.moveForward();
		// temp->previous->next = temp->next->previous;
		// temp->next->previous = temp->previous->next;
		//delete temp;//might be pointless so check
		delete (deleter.current -> previous);
		count--;
	}
			head->next = tail;
		tail -> previous = head;
}
void printList(List& source, bool direction){
	if(direction){
		ListItr printer = source.first();
		while((printer.isPastEnd()) != true){
			cout << printer.retrieve() << endl;
			printer.moveForward();
		}
	}else{
		ListItr printer = source.last();
		while((printer.isPastBeginning()) != true){
			cout << printer.retrieve() << endl;
			printer.moveBackward();
		}
	}
}
