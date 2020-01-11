//Used code created by Aaron Bloomfield
//Joseph ELsisi jre3wjh
//Lab 108
//Nov 25
#include "huffNode.h"
#include <cstddef>
using namespace std;
huffNode::huffNode(char c, int f){
	value = c;
	frequency = f;
	left = NULL;
	right = NULL;
}