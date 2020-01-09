/*
 *Joseph Elsisi
 *Sept 16
 *jre3wjh
 Stack.cpp
 */
#include "ListNode.h"
#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack():count(0){
	head = new ListNode;
	tail = new ListNode;
	head -> next = tail;
	head -> previous = NULL;
	tail -> previous = head;
	tail -> next = NULL;
}
Stack::~Stack(){
	makeEmpty();
	delete this->head;
	delete this->tail;
}


void Stack::push(int x){
	ListNode *newNode = new ListNode;
	newNode -> value = x;
	newNode -> next = head -> next;
	newNode -> previous = head;
	head -> next -> previous = newNode;
	head -> next = newNode;
	count++;//NEW ADD
}
void Stack::pop(){
	head -> next -> next -> previous = head;
	ListNode *listpoint = head -> next;
	head -> next =  head -> next -> next;
	delete listpoint;
}
int Stack::top(){
	return (head -> next -> value);
}
int Stack::size() const{ 
	return count;
}
bool Stack::isEmpty() const{
	if((this-> count) == 0){
		return true;
	}
	else{
		return false;
	}
}
void Stack::makeEmpty(){
	while(head -> next != tail){
		pop();
		count--;
	}
}
