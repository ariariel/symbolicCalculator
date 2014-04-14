#include <iostream> 
#include <string>
#include <sstream>
#include <stack>
#include <map>
#include <vector>
#include <cstdlib>
#include <stdexcept>

#include "Operator.h"
#include "Input.h"
#include "Integer.h"
using namespace std;


vector<char> conversion(string x) {
	vector<char> data(x.begin(), x.end());
	return data;
}
vector<Input*> conversion2(vector<char> rpn){
	vector<Input*> input;
	for(int i=0; i<rpn.size(); i++){
		if(isdigit(rpn[i])){
			input.push_back(new Integer(rpn[i]-'0'));
		}
		else if(rpn[i]=='+'||rpn[i]=='-'||rpn[i]=='/'||rpn[i]=='*'||rpn[i]=='^'){
			input.push_back(new Operator(rpn[i]));
		}
	}
	return input;
}
vector<string> toStringVec(string expr){
	vector<string> stringVec;
	int count=0;
	for(int i =0; i<expr.size();i++){
		if((expr.at(i)=='+')||(expr.at(i)=='-')||(expr.at(i)=='/')||(expr.at(i)=='*')||(expr.at(i)=='^')){
			stringstream ss;
			stringVec.push_back(expr.substr(count,i-count));
			ss<<expr.at(i);
			stringVec.push_back(ss.str());
			ss.str("");
			count = i+1;
		}
	}
	if(expr.at(count)){
		stringVec.push_back(expr.substr(count, expr.at(expr.size()-1)));
	}
	return stringVec;
}

vector<string> shuntYard(string x) {
	vector<string> expr = toStringVec(x);
	vector<string> queue;  stack<char> opStack;
	map<char, int> opPrec;
	opPrec['('] = -1;
	opPrec['+'] = 1; opPrec['-'] = 1;
	opPrec['*']  = 2; opPrec['/']  = 2;
	opPrec['^']  = 3; opPrec['sqrt']  = 3;
	bool lastWasOp = true;
	for(int i=0;i<expr.size();i++){
		if((expr[i]=="+")||(expr[i]=="-")||(expr[i]=="/")||(expr[i]=="*")||(expr[i]=="^")){
			switch (expr[i].at(0)) {
		    case '(':
		      opStack.push('(');
		      break;
		    case ')':
		      while (opStack.top()!=('(')) {
		      	stringstream ss;
		      	ss<<opStack.top();
		        queue.push_back(ss.str());
		        opStack.pop();
		      }
		      opStack.pop();
		      break;
		    default:  //op precedence
		      	{
		        if (lastWasOp) {
		          // Convert unary operators to binary in the RPN.
		          if (expr[i]=="-" || expr[i]=="+") {
		            queue.push_back("0");
		          } else {
		            throw domain_error(
		                "Unrecognized unary operator.");
		          }
		        }

		        while (!opStack.empty() &&
		            (opPrec[expr[i].at(0)] <= opPrec[opStack.top()])) //comparing stack operators
		        {
		          stringstream ss;
		          ss<<opStack.top(); 		
		          queue.push_back(ss.str());
		          opStack.pop();
		        }

		        opStack.push(expr[i].at(0));
		        lastWasOp = true;
		      }
		  }
		}
		else {
			// If the string is a number, add it to the output queue.
			queue.push_back(expr[i]);
			lastWasOp = false;
		}
	} 
	while(!opStack.empty()){   //empty the final stack
		stringstream ss;
		ss<<opStack.top();
    	queue.push_back(ss.str());
    	opStack.pop();

    }
	return queue;
}


int main(){
string a = "44+44-3/333*99";
vector<string> vec = toStringVec(a);
for (int i = 0; i < vec.size(); ++i)
{
	cout<< vec[i];
}

// vector<string> output = shuntYard(a);
// for (int i = 0; i < output.size(); ++i)
// {
// 	cout<< output[i];
// }
//vector<Input*> input = conversion2(output);
//TESTING - cast the subclass upon the superclass to be able to access subclass methods
// Calculator* calc = new Calculator();
// calc->setVec(input);
// calc->solve();
// vector<Input*> result = calc->getVec();
// Integer* test = (Integer*)result[0];
// cout<< test->getInteger();
}
