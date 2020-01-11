//Used code created by Aaron Bloomfield
//Joseph ELsisi jre3wjh
//Lab 108
//Nov 25
#include "heap.h"
#include "huffNode.h"
#include <iostream>
#include <cstddef>
using namespace std;
heap::heap(){}
huffNode * heap::findMin(){
	return table[1];
}
heap::~heap(){
	//todo
	for(int i = 1; i < table.size(); i++){
		delete table[i];
	}
}
huffNode * heap::deleteMin(){
	if(table.size() == 0){
		return NULL;
	}
	huffNode * ret = table[1];
	table[1] = table[table.size() - 1];
	table.pop_back();
	percolateDown(1);
	return ret;
}
void heap::percolateDown(int i){
	huffNode * c = table[i];
	while(i*2 <= table.size()){
		int child = i * 2;
		if((child+1 <= table.size()) && (table[child+1] -> frequency < table[child] -> frequency)){
			child++;
		}
		if(c -> frequency > table[child] -> frequency){
			table[i] = table[child];
			i = child;
		} else{
			break;
		}
	}
	table[i] = c;
}
void heap::percolateUp(int i) {
    huffNode * c = table[i]; //switch to node 
    for ( ; (i > 1) && (c -> frequency < table[i/2] -> frequency); i /= 2){
        table[i] = table[i/2];
    }
    table[i] = c;
}
void heap::insert(huffNode *c){
	table.push_back(c);
	percolateUp(table.size() - 1);
	//now percolate up!!
}
void heap::printTable(huffNode * c){
	if(c != NULL){
		cout << c -> value << " is " << c -> frequency << endl;
		printTable(c -> left);
		printTable(c -> right);
	}
}
void heap::buildHuffman(){
	while(table.size() != 2){
		huffNode * tmp1 = deleteMin();
		huffNode * tmp2 = deleteMin();
		int tempNum = (tmp1 -> frequency) + (tmp2 -> frequency);
		huffNode * dummy = new huffNode('$', tempNum);
		dummy -> left = tmp1;
		dummy -> right = tmp2;
		//need to add a left and right child to huffNode! leaves will be set to null.
		this -> insert(dummy);
		//table.pop_back();
	}
}