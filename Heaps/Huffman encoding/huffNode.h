//Used code created by Aaron Bloomfield
//Joseph ELsisi jre3wjh
//Lab 108
//Nov 25
#ifndef HUFFNODE_H
#define HUFFNODE_H
using namespace std;

class huffNode{
	public:
		huffNode(char c, int f);
		char value;
		int frequency;	
		huffNode * left;
		huffNode * right;
};
#endif