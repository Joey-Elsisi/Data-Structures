/*
Joseph Elsisi
jre3wjh
Septeber 13
*/
#include <string>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ostream>
#include "postfixCalculator.h"

using namespace std;

int main(){
PostFixCalculator p;
    string input;
    cout << "Enter your numbers/operators" << endl;
    getline(cin, input);
    int outcome = p.calculate(input);
    cout << "Result is: " << outcome << endl;
    return 0;
}