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

/*
void findNthRoot(string y) {
    size_t position = y.find("rt:");
	if (position != string::npos)
	{
		size_t length = 1;
		size_t n = position - 1;
		while (n > 0 && isdigit(y[n - 1])) {
			--n;
			++length;
		}
		string str1 = y.substr(n, length);
        
		length = 1;
		size_t x = position + 3;
        if(y.at(x) == '(') {
            int otherPar1 = y.find(')');
            int otherPar2 = y.find('(');
            int otherPar = otherPar1 - otherPar2 - 1;
            string str3 = y.substr(x+1, otherPar); 
            cout << str3;
        }
        else {
		    while (x < y.size() - 1 && isdigit(y[x + length]))
			    ++length;
		    string str2 = y.substr(x, length);
		    int a = stoi(str1);
		    int b = stoi(str2);
            cout << "a: " << a << "\n" << "b: " << b;
		    nthRootToExponent(a, b);
        }
	}
} */
/*
void nthRootToExponent(int x, int y) {
	string x1 = to_string(x);
	string y1 = to_string(y);
	stringstream ss;
	ss << y << "^" << "1/" << x;
	cout << ss.str() << endl;
}
*/

/*Menu accessed by user- in order to compute a new expression, the user needs to select the first option and then type the expression
as they would normally. In order to obtain the previous answer solved, option 2 needs to be called. */
void menu(){

	//create calculator object to access previous answer
	char keepRunning = 'y';
	string userInput;
	string input;

	while(keepRunning){

	cout << "Welcome to the Calculator's main menu!" << endl;
	cout << "Please make a selection: " << endl;
	cout << "1: Compute New Expression" << endl;
	cout << "2: Help" << endl;
	cout << "3: Quit" << endl;
	cout << endl;

	cin >> userInput;
	cout << endl;

		if(userInput == "1"){
			Calculator calc = Calculator();
		    string input;
			char keepRun = 'y';
			while(keepRun){
			cout << "Please type in the expression you wish to solve." << endl;
			cout << "Note: to use your last answer in the expression, use the syntax 'ans'." << endl;
			cout << "To exit this option, type 'back' or 'quit'." << endl;
			cout << endl;
			cin >> input;
			if(input == "back" || input == "Back" || input == "Quit" || input == "quit"){
				break;
			}
			//if the input contains ans, then call AnsParse to substitute
			//call method to findIrrational??
			//input = findNthRoot(input);
			//input = AnsParse(input);

			vector<char> conv = shuntYard(input);
			conv = conversion(input);
			vector<Input*> converted = conversion2(conv);
			calc.setVec(converted);
			//calc.solve();

			//two, pass vector of input to solve




			cout << endl;
			//call the necessary methods in order to put into RPN method, conversion, and solve. Or will ShuntYardAlg call these
			//methods for us?
			}
		}

		else if(userInput == "2"){
			string helpinput;
			char keepItRunning = 'y';
			while(keepItRunning){
				cout << "Welcome to the help screen." << endl;
				cout << "Please pick the query that your question relates to." << endl;
				cout << "1: Operator Syntax" << endl;
				cout << "2: Limits on Functionality" << endl;
				cout << "To exit this option, type 'back' or quit'." << endl;
				cout << endl;
				cin >> helpinput;
				cout << endl;

			if(helpinput == "1"){
				cout << "This calculator provides a specific functionality. Please be sure to use the correct suntax " 
				 << "when inputting expressions to solve. " << endl;
				cout << "Operator syntax: " << endl;
				cout << "The square root of x: sqrt:x" << endl;
				cout << "X to the power of y: x^y" << endl;
				cout << "The nth root of x: nrt:x (where 'n' is replaced by a number)" << endl;
				cout << "Log base b of x: log_b:x" << endl;
			}

			else if(helpinput == "2"){
				cout << "This program supports the following number types: " << endl;
				cout << "Integers (whole numbers), rational numbers (fractions), pi, e, and nth-root irrationals. " << endl;
				cout << "The program also supports exponentials. However, this doesn't include x^pi or x^e. " << endl;
				cout << "For multiplication using irrationals, please add a multiplication sign between the symbols." << endl;
				cout << "When subtracting a negative element, please use parenthesis to separate the postive and negative number." << endl;
				cout << "You may have a space between a pair of operators, numbers, or operator-number pair." << endl;
			}

			else if(helpinput == "back" || helpinput == "Back" || helpinput == "Quit" || helpinput == "quit"){
				break;
				}

			else {
				cout << "Please choose one of the specified options." << endl;
			}
				cout << endl;
			}
		}

		else if(userInput == "3"){
			break;
		}

		else {
			cout << "Please choose one of the specified options." << endl;
			cout << endl;
		}
	}
}


int main(){
	menu();

/*string a = "4-6";
vector<char> output = shuntYard(a);
vector<Input*> input = conversion2(output);
//TESTING - cast the subclass upon the superclass to be able to access subclass methods
Calculator* calc = new Calculator();
calc->setVec(input);
calc->subtract(0); */

//for (int i = 0; i < input.size(); i++)
//(Integer*)input[i].getInteger();
}
