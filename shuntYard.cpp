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


vector<char> shuntYard(string x) {
	vector<char> expr = conversion(x);
	vector<char> queue;  stack<char> opStack;
	map<char, int> opPrec;
	opPrec['('] = -1;
	opPrec['+'] = 1; opPrec['-'] = 1;
	opPrec['*']  = 2; opPrec['/']  = 2;
	opPrec['^']  = 3; opPrec['sqrt']  = 3;
	bool lastWasOp = true;
	for(int i=0;i<expr.size();i++){
		if(isspace(expr[i])){
			i++;
		}
		if (isdigit(expr[i])) {
			// If the char is a number, add it to the output queue.
			queue.push_back(expr[i]);
			lastWasOp = false;
		}
		else{
			switch (expr[i]) {
		    case '(':
		      opStack.push('(');
		      break;
		    case ')':
		      while (opStack.top()!=('(')) {
		        queue.push_back(opStack.top());
		        opStack.pop();
		      }
		      opStack.pop();
		      break;
		    default:  //op precedence
		      	{
		        if (lastWasOp) {
		          // Convert unary operators to binary in the RPN.
		          if (expr[i]=='-' || expr[i]=='+') {
		            queue.push_back('0');
		          } else {
		            throw domain_error(
		                "Unrecognized unary operator.");
		          }
		        }

		        while (!opStack.empty() &&
		            (opPrec[expr[i]] <= opPrec[opStack.top()])) //comparing stack operators
		        {
		          queue.push_back(opStack.top());
		          opStack.pop();
		        }

		        opStack.push(expr[i]);
		        lastWasOp = true;
		      }
		  }
		}
	} 
	while(!opStack.empty()){   //empty the final stack
    	queue.push_back(opStack.top());
    	opStack.pop();

    }
	return queue;
}


int main(){
string a = "4/2";
vector<char> output = shuntYard(a);
vector<Input*> input = conversion2(output);
//TESTING - cast the subclass upon the superclass to be able to access subclass methods
Calculator* calc = new Calculator();
calc->setVec(input);
calc->divide(0);
}
