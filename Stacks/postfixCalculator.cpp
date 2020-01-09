/*
Joseph Elsisi
jre3wjh
Septeber 13
postfixCalculator.cpp
*/
#include "postfixCalculator.h"
#include "Stack.h"
#include "ListNode.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

PostFixCalculator::PostFixCalculator(){
	Stack holder;
}
void PostFixCalculator::pushNum(int x){
	holder.push(x);
}
int PostFixCalculator::top(){
	if(holder.isEmpty()){
		cout << "ERROR: this stack is empty";
		exit(-1);
	}
	return holder.top();
}
void PostFixCalculator::remove(){
		if(holder.isEmpty()){
		cout << "ERROR: this stack is empty";
		exit(-1);
	}
	holder.pop();
}
bool PostFixCalculator::empty(){
	return holder.isEmpty();
}
void PostFixCalculator::add(){
	int x = holder.top();
	holder.pop();
	int y = holder.top();
	holder.pop();
	holder.push(x+y);
}
void PostFixCalculator::subtract(){
	int x = holder.top();
	holder.pop();
	int y = holder.top();
	holder.pop();
	holder.push(y-x);
}
void PostFixCalculator::multiply(){
	int x = holder.top();
	holder.pop();
	int y = holder.top();
	holder.pop();
	int final_val = x * y;
	holder.push(final_val);
}
void PostFixCalculator::divide(){
	int x = holder.top();
	holder.pop();
	int y = holder.top();
	holder.pop();
	holder.push(y/x);
}
void PostFixCalculator::negate(){
	int x = holder.top();
	holder.pop();
	holder.push((-1) * x);
}
int PostFixCalculator::calculate(string s){
	int size = s.size();
	vector <string> arr(size);
	int count = 0;
	int listItr = 0;
	int last_index = 0;
	for(int i = 0; i < size; i++){
		if(s[i] == ' '){
			arr[listItr] = s.substr(last_index, (i - last_index));
			listItr++;
			last_index = i + 1;
		}
		if(i == (size - 1)){
			arr[listItr] = s.substr(last_index, ((i + 1) - last_index));//CATION
			listItr++;
		}
	}
	for(string val : arr){
		if(val.size() > 1){
			if(isdigit(val[1])){
				pushNum(stoi(val));
			}
		} else{
			if(isdigit(val[0])){
				pushNum(stoi(val));
			}
			else{
				char curr = val[0];
				switch(curr){
					case '+':
						add();
						break;
					case '-':
						subtract();
						break;
					case '*':
						multiply();
						break;
					case '/':
						divide();
						break;
					case '~':
						negate();
						break;
				}
			}
		}
	}
	return top();
}