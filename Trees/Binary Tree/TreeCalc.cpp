/*
Joseph Elsisi
jre3wjh
October 13
TreeCalc.cpp
*/
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include "TreeNode.h"
#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
    stack <TreeNode *> mystack;
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
    //check if stack is empty, if not, stack.top the pointer and put it in cleanTree
    if(!mystack.empty()){
        cleanTree(mystack.top());
    }
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
    if (((ptr -> left) == NULL) && (ptr -> right) == NULL){
        int doNothing;
    } else {
    cleanTree(ptr->left);
    cleanTree(ptr->right);
    }
    delete ptr;
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
    if(isdigit(val[0]) || val.size() == 2){
        mystack.push(new TreeNode(val));
    } else{
        TreeNode * operate = new TreeNode(val);
        operate -> right = mystack.top();
        mystack.pop();
        operate -> left = mystack.top();
        mystack.pop();
        mystack.push(operate);
    }
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
    // print the tree in prefix format
    if(ptr != NULL){
    cout << (ptr -> value) << " ";
    printPrefix(ptr -> left);
    printPrefix(ptr -> right);
}
}


//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr, bool isRightDigit) const {
    //print tree in infix format with appropriate parentheses
    //CURRENTLY SEG FAULTS
    if(ptr != NULL){
        if((!isdigit(ptr -> value[0]))){
            if((ptr -> value).size() != 2){
            cout << "(";
        }
    }
        printInfix((ptr -> left), false);
        if(((ptr -> value[0]) == '\\') || ((!isdigit(ptr -> value[0])) && ((ptr -> value).size() != 2))){
                    cout << " " << (ptr -> value) << " ";;
        } else if(isRightDigit){
            cout << (ptr -> value);
        } else{
            cout << (ptr -> value); //WARNING add last space back
        }

        if((!isdigit(ptr -> value[0]))){ //if not a digit
            if((ptr -> value).size() != 2){
            printInfix((ptr -> right), true);
        }} else{
            printInfix((ptr -> right), false);
        }

        if((!isdigit(ptr -> value[0]))){
            if((ptr -> value).size() != 2){
            cout << ")";
        }
    }
}
}
int TreeCalc::stringToInt(string str) const{
     return stoi(str);
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    // print the tree in postfix form
    if(ptr != NULL){
        printPostfix(ptr -> left);
        printPostfix(ptr -> right);
        cout << (ptr -> value) << " ";
    }
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (mystack.size()!=0 && mystack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        printPostfix(mystack.top());
        // call your implementation of printPostfix()
        cout << endl;
        cout << "Expression tree in infix expression: ";
        // call your implementation of printInfix()
        printInfix(mystack.top(), false);
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        // call your implementation of printPrefix()
        printPrefix(mystack.top());
        cout << endl;
    } else
        cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::doTheMath(TreeNode* ptr, int left, int right) const{
    int temp = 0;
            char curr = (ptr -> value[0]);
                switch(curr){
                    case '+':
                        temp = left + right;
                        break;
                    case '-':
                        temp = left - right;
                        break;
                    case '*':
                        temp = left * right;
                        break;
                    case '/':
                        temp = left / right;
                        break;
                }
                return temp;
        }
bool TreeCalc::isOperator(string val) const{
    if((!isdigit(val[0]))){
            if((val).size() != 2){
                return true;
            }
        }
        return false;
}
int TreeCalc::calculate(TreeNode* ptr) const{
    int total = 0;
    if(ptr == NULL){
        return 0;
    }else if (((ptr -> left) == NULL) && (ptr -> right) == NULL){
        return stringToInt(ptr -> value);
    }
    int leftNum = calculate(ptr -> left);
    int rightNum = calculate(ptr -> right);
    return doTheMath(ptr, leftNum, rightNum);
 }
 
//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    // call private calculate method here
    i = calculate(mystack.top());
    return i;
}
