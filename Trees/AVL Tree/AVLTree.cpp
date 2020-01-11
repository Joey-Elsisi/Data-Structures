//Joseph Elsisi jre3wjh
//108
//october 17
#include "AVLTree.h"
#include <string>
#include <iostream>
#include "AVLNode.h"
using namespace std;

AVLTree::AVLTree() { root = NULL; }

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    root = insertHelp(root, x);
}
//Helper function
AVLNode* AVLTree::insertHelp(AVLNode* n, const string& x){
// insert finds a position for x in the tree and places it there.
    if(n == NULL)
    {
        return new AVLNode(x);
    }
    else if(x.compare(n->value) < 0){
        // n->height = 1 + max(height(n->left), height(n->right));
        n -> left = insertHelp(n -> left, x);
        n->height = 1 + max(height(n->left), height(n->right));
        n = balance(n);
        n->height = 1 + max(height(n->left), height(n->right));
    }
    else if(x.compare(n->value) > 0){
         //n->height = 1 + max(height(n->left), height(n->right));
        n -> right = insertHelp(n -> right, x);
        n->height = 1 + max(height(n->left), height(n->right));
        n = balance(n);
        n->height = 1 + max(height(n->left), height(n->right));
    }
//    cout << n -> value << "'s height is" << height(n) << endl;
    return n;
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) { root = remove(root, x); }

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
//helper
string AVLTree::pathToHelper(AVLNode * n, const string& x) const {
    if(!find(x)){
        return " ";
    }
    string find = x;
    string final = " ";
    if(n ->left == NULL && n->right == NULL)
    {
        return final + (n -> value);
    }
    else if(find.compare(n->value) < 0){
        final += (n -> value) + pathToHelper(n -> left, find);
    }
    else if(find.compare(n->value) > 0){
        final += (n -> value) + pathToHelper(n -> right, find);
    }
    return final;
}
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    string final = pathToHelper(root, x);
    return final;
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode * currNode = root;
    while(currNode != NULL){
        if(currNode -> value == x) {
            return true;
        } else if(x < currNode -> value){
            currNode = currNode -> left;
        } else{
            currNode = currNode -> right;
        }
    }
    return false;
}
//helper
int AVLTree::counterHelp(AVLNode* node) const{
   int total = 0;
    if(node == NULL){
        return 0;
    }
    if((node->left == NULL && node->right == NULL)){
        return 0; //zero or one?
    }
    if(node -> left != NULL){
        total += 1 + counterHelp(node -> left);
    }
    if(node -> right != NULL) {
        total += 1 + counterHelp(node->right);
    }
    return total;
}
// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
    int count = 1;
    count += counterHelp(root);
    return count;
}
//int AVLTree::balanceFactor(AVLNode*& n) const{
//    int left;
//    int right;
//  if(n == NULL){
//        return 0;
//    }
//    if(n -> left == NULL){
//        left = -1;
//    } else {
//        left = n -> left -> height;
//    }
//    if(n -> right == NULL){
//        right = -1;
//    } else{
//        right = n -> right -> height;
//    }
//    int balanceFactor = right - left;
//    return balanceFactor;
//}
// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
AVLNode* AVLTree::balance(AVLNode*& n){
    // YOUR IMPLEMENTATION GOES HERE
    if(n == NULL){
        return n;
    }
    int left;
    int right;
    if(n -> left == NULL){
        left = -1;
    } else {
        left = n -> left -> height;
    }
    if(n -> right == NULL){
        right = -1;
    } else{
        right = n -> right -> height;
    }
    int balanceFactor = right - left;
    if(balanceFactor <= -2) {

        if (height(n->left->left) >= height(n->left->right)){
            n = rotateRight(n);
        } else {
            AVLNode * temp = rotateLeft(n -> left);
            n -> left = temp;
            n = rotateRight(n);
//            n = rotateLeft(n);
        }
        //do a right rotation
    }
    else if(balanceFactor >= 2){
        //do a left

        if (height(n->right->right) >= height(n->right->left)){
            n = rotateLeft(n);
        } else {
            AVLNode * temp_2 = rotateRight(n -> right);
            n -> right = temp_2;
            n = rotateLeft(n);

        }
    }
    return n;

}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode * temp = n -> right;
    n -> right = temp -> left;
    temp -> left = n;
    n -> height = 1 + max(height(n->left), height(n->right));
    temp -> height = 1 + max(height(n->left), height(n->right));

    return temp;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode * temp = n -> left;
    n -> left = temp -> right;
    temp -> right = n;
    n -> height = 1 + max(height(n->left), height(n->right));
    temp -> height = 1 + max(height(n->left), height(n->right));
    return temp;
}

// private helper for remove to allow recursion over different nodes. returns
// an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }
    // first look for x
    if (x == (n->value)) {
        // found
        // no children
        if (n->left == NULL && n->right == NULL) {
            delete n;
            n = NULL;
            return NULL;
        }
        // single child
        if (n->left == NULL) {
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        }
        if (n->right == NULL) {
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        }
        // two children -- tree may become unbalanced after deleting n
        string sr = min(n->right);
        n->value = sr;
        n->right = remove(n->right, sr);
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);
    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node. If the node is
// null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
    if (p == nullptr) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) { // github user @willzhang05 pointed out that I forgot to change this from isLeft to isRight on my first commit
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

    printTree(root->left, trunk, false);
}

void AVLTree::printTree() { printTree(root, NULL, false); }