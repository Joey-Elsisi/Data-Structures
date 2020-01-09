/*
Joseph Elsisi
jre3wjh
Septeber 13
postfixCalculator.h
*/
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PostFixCalculator{
public:
    PostFixCalculator();
    int calculate(string s);
    bool empty();

private:
    Stack holder;
    void pushNum(int num);
    int top();
    void remove();
    void add();
    void subtract();
    void multiply();
    void divide();
    void negate();
};


#endif