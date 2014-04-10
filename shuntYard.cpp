#include <iostream> 
#include <string>
#include <sstream>
#include <stack>
#include <map>
#include <vector>
#include <cstdlib>
#include <stdexcept>
using namespace std;


vector<char> conversion(string x) {
	vector<char> data(x.begin(), x.end());
	return data;
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
string a = "-4";
vector<char> output = shuntYard(a);
for (int i =0; i<output.size(); i++){
	cout<<output[i];
}

}
