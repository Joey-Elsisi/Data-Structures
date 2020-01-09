#include "BinarySearchTree.h"
#include "BinaryNode.h"

#include <iostream>
using namespace std;

int main() {
  BinarySearchTree bst;
  while (cin.good()) {
    string instr, word;
    cin >> instr;
    cin >> word;
    if (instr == "I") {
      bst.insert(word);
    } else if (instr == "R") {
      bst.remove(word);
    } else if (instr == "L") {
      cout << "BST path: " << bst.pathTo(word) << endl;
    }
  }
  cout << "BST numNodes: " << bst.numNodes() << endl;
}


// int main() {
//   BinarySearchTree bst;
//   cout << "is this working 1?";
//   bst.insert("HI");
//   cout << "is this working 2?";
//   bst.insert("BYE");
//   cout << "is this working 3?";
//   bst.insert("UIH");
//   bst.insert("UHSYD");
//   cout << "is this working?";
//   // bst.remove(word);
//   // cout << "BST path: " << bst.pathTo("Hi") << endl; 
//   // cout << "BST numNodes: " << bst.numNodes() << endl;
//   // cout << "The entire tree: DELETE THIS LATER" << endl;
//   bst.printTree();
//  }