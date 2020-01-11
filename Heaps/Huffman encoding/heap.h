//Used code created by Aaron Bloomfield
//Joseph ELsisi jre3wjh
//Lab 108
//Nov 25
#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include "huffNode.h"
#include <cstddef>

using namespace std;
class heap{
public:
	heap();
	~heap();
	huffNode * findMin();
	void insert(huffNode * c);
	huffNode * deleteMin();
	void printTable(huffNode * c);
	void buildHuffman();
private:
	vector <huffNode *> table = {NULL};
	void percolateUp(int i);
	void percolateDown(int i);
	int tableSize = 0;
};

#endif