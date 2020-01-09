#include "BinaryNode.h"
#include <string>
using namespace std;

BinaryNode::BinaryNode(string x) {
  value = x;
  left = NULL;
  right = NULL;
}

BinaryNode::~BinaryNode() {
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}