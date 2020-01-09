#include "BinarySearchTree.h"
#include <string>
#include "BinaryNode.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree() { root = NULL; }

BinarySearchTree::~BinarySearchTree() {
  delete root;
  root = NULL;
}

BinaryNode* BinarySearchTree::insertHelp(BinaryNode* node, const string& x) const{
// insert finds a position for x in the tree and places it there.
  if(node == NULL)
  {
    return new BinaryNode(x);
  }
  else if(x.compare(node->value) < 0){
       node = insertHelp(node -> left, x);
  }
  else{
   node = insertHelp(node -> right, x);
  }
  return node;
}
//   if(node == NULL)
//   {
//   // if(node -> left == NULL){
//   //   if(node -> right == NULL){
//        if(x.compare(node->value) < 0){
//        node -> left = new BinaryNode(x);
//        return;
//       } else{
//       node -> right = new BinaryNode(x);
//       return;
//       }
//   } 
//   else if(x.compare(node->value) < 0)
//   {
//        insertHelp(node -> left, x);
//        return;
// } 
// else
// {
//   insertHelp(node -> right, x);
//   return;
// }
// }

void BinarySearchTree::insert(const string& x) {
  // YOUR IMPLEMENTATION GOES HERE
  BinaryNode * john = insertHelp(root, x);
}
//   bool inserted = false;
//   if(root == NULL){
//     root = new BinaryNode(x);
//     cout << "root is null!" << endl;
//     return;
//   }
//   BinaryNode * currNode = root; //is this a pointer?
//   while(!inserted){
//   cout<<"attempting insert" << endl;
//   if(currNode -> left == NULL){
//     if(currNode -> right == NULL){
//     currNode -> value = x;
// }
//   } 
//     else if(x.compare(currNode->value) < 0){
//       if(currNode -> left == NULL){
//       currNode -> left = new BinaryNode(x);
//       inserted = true;
//   } else{
//       currNode = (currNode -> left);
//   }
// }
//   else{
//     if(currNode -> right == NULL){
//     currNode -> right = new BinaryNode(x);
//     inserted = true;
//     } else{
//     currNode = (currNode -> right);
//       }
//     }
//   }
// }


// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) { 
  root = remove(root, x); 
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE

  return NULL;
}

 // bool BinarySearchTree::find()
// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  return NULL;
}
int BinarySearchTree::counterHelp(BinaryNode* node) const{
    int total = 0;
    if(node == NULL){
        return 0;
    }else {
        return 1;
    }
    int leftNum = counterHelp(node -> left);
    int rightNum = counterHelp(node -> right);
    return leftNum + rightNum;
}
// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const {
  // YOUR IMPLEMENTATION GOES HERE
    int total = counterHelp(root);
    return total++;
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
  // first look for x
  if (x == n->value) {
    // found
    // no children
    if (n->left == NULL && n->right == NULL) {
      delete n;
      n = NULL;
      return NULL;
    }
    // single child
    if (n->left == NULL) {
      BinaryNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    if (n->right == NULL) {
      BinaryNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    // two children
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  return n;
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == nullptr) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isLeft) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->left, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isLeft) {
    trunk->str = ".---";
    prev_str = "   |";
  } else {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << root->value << endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->right, trunk, false);
}

void BinarySearchTree::printTree() { printTree(root, NULL, false); }