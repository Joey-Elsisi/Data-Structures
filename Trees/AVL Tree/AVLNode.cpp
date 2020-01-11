//Joseph Elsisi jre3wjh
//108
//october 17
#include "AVLNode.h"
#include <string>
using namespace std;

AVLNode::AVLNode() {
    value = "?";
    left = NULL;
    right = NULL;
    height = 0;
}

AVLNode::AVLNode(string val) {
    value = val;
    left = NULL;
    right = NULL;
    height = 0;
}

AVLNode::~AVLNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}