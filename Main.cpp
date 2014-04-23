/*
Calculator project by Ariel Farias, Marie Urmano, Quaide Tranter, Arturo Esquivel, and Matt Cabral
COP 3503
Section 129B
*/
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
#include "Calculator.h"
#include "Rational.h"
using namespace std;

/*Conversion takes in an input from the user and returns the data as a vector of characters. */
vector<char> conversion(string x) {
	vector<char> data(x.begin(), x.end());
	return data;
}

/*Conversion2 takes in a vector of string sorted from the Reverse Polish notation method and converts it into
a vector of Input pointers, assigning each respective value to its subclass. */
vector<Input*> conversion2(vector<string> rpn){
	vector<Input*> input;
	for(int i=0; i<rpn.size(); i++){
		if(rpn[i]=="+"||rpn[i]=="-"||rpn[i]=="/"||rpn[i]=="*"||rpn[i]=="^"||rpn[i]=="("||rpn[i]==")"){
			input.push_back(new Operator(rpn[i].at(0)));
					Operator* o = (Operator*)(input[i]);
					cout << o->getOperand() << "this is the type of operand in input vector" <<endl;
		}
		else{   //push the integer, or the irrational, depending on what it is
			string a = rpn[i];
			if(a == ("e")|| a ==("pi")){
				input.push_back(new Irrational(a));
				Irrational* irr = (Irrational*)(input[i]);
				cout << irr->getIrrational() << "this is the type of irrational in input vector" << endl;
				//now for all operations, create an add, subtract, multiply, divide, power methods for irrational in irrational class.
				//will need to append the string, etc for all
				
			}
			else{input.push_back(new Integer(atoi(a.c_str())));
							Integer* in = (Integer*)(input[i]);
							cout << in->getInteger() << "this is the type of integer in input vector" << endl;
			}
		}
			//cout << typeid(input[i]).name() << " This is the type of the data in RPN vec" << endl;
	}
		return input;
}

string findSqRoot(string y) {
    stringstream ss; 
 while(y.find("sqrt:") != string::npos){
    size_t position = y.find("sqrt:");
    size_t last = y.find_last_of("sqrt:");
        size_t length = 1;
        size_t n = position - 1;
        length = 1;
    	size_t x = position + 5;
        
		string str1 = y.substr(0, position);
        ss << str1;
        
        if(y.at(x) == '(') {
            int otherPar1 = y.find(')');
            int otherPar2 = y.find('(');
            int otherPar = otherPar1 - otherPar2 - 1;
            string str3 = y.substr(x+1, otherPar); 
        }
        else {
		    while ((x < y.size()) && isdigit(y[(x) - (length)])){
					++length;
			}   
				string str2 = y.substr(x, length+1000000000000);
                int b = stoi(str2);
                
                
                if(((int)position - 1) >= 0){
                    if(y.at(((int)position - 1)) == '-'){
                    string str = ss.str();
                    ss.str("");
                    str.pop_back();
                        if(!str.empty()){
                        ss << str << "+";
        			    }
					    else{
					    ss << str;
					    } 
                         ss << b << "^" << "(-1/2)";
                    }
                    else{
                    ss << b << "^" << "(1/2)";
                    }   
                }
                else{
                    ss << b << "^" << "(1/2)";
                }
                
                stringstream bb;
                bb << b;
                string NumValue = bb.str();
                size_t expressionValue = y.find(NumValue, position);
                
                string str4 = y.substr(expressionValue+NumValue.length(), y.length());
                ss << str4;
            
			y = ss.str();
			ss.str("");
	} 
 }
         cout << y << " this is y's value"<< endl;
    	return y;
}
/* 
findNth root searches for nrt: operators within the string and returns them, reparsed into the string, as exponents for our shunting yard algorithm.
*/
string nthRootToExponent(int x, int y) {
	stringstream ss;
	ss << y << "^" << "(1/" << x << ")";
	return ss.str();
}

//NTH ROOT NEEDS TO WORK WITH NUMBERS BIGGER THAN NINE CHARACTERS. Right now it only functions with up to nine.
string findNthRoot(string y) {
    stringstream ss;
    while(y.find("rt:") != string::npos){
    size_t position = y.find("rt:");
    if ((position != string::npos)){
		size_t length = 1;
		size_t n = position - 1;
		while (n > 0 && isdigit(y[n - 1])) {
			--n;
			++length;
		}
		string str1 = y.substr(0, position-1);
        string str5 = y.substr(n, length);
		int a = stoi(str5);
        ss << str1;
        
		length = 1;
		size_t x = position + 3;
        if(y.at(x) == '(') {
            int otherPar1 = y.find(')');
            int otherPar2 = y.find('(');
            int otherPar = otherPar1 - otherPar2 - 1;
            string str3 = y.substr(x+1, otherPar);
        }
        else {
		    while ((x < y.size()) && isdigit(y[(x) - (length)])){
					++length;
			}   //only works to nine characters (the base number)
				string str2 = y.substr(x, length+1000000000000);
                
				int b = stoi(str2);
                
                stringstream cc;
                cc << a;
                string aValue = cc.str();
                
                if((int)(position - aValue.length() - 1) >= 0){
                    if(y.at(((int)position - aValue.length() - 1)) == '-'){
                    string str = ss.str();
                    ss.str("");
                    str.pop_back();
                        if(!str.empty()){
                        ss << str << "+";
    				    }
					    else{
					    ss << str;
					    } 
                         ss << b << "^" << "(-1/" << a << ")";
                    }
                
                
                    else{
                    ss << b << "^" << "(1/" << a << ")";
                    }   
                }
                else{
                    ss << b << "^" << "(1/" << a << ")";
                }
        
                stringstream bb;
                bb << b;
                string NumValue = bb.str();
                size_t expressionValue = y.find(NumValue, position);
              
            
            string str4 = y.substr(expressionValue+NumValue.length(), y.length());
            ss << str4;
            
            y = ss.str();
            ss.str("");
	}
    }
} 
cout << y << endl;
return y;
}

/* toStringVec takes in a string expression and turns it into a vector of strings, accounting for double digits.
*/
vector<string> toStringVec(string expr){
	cout << expr<< endl;
	size_t position = expr.find("rt:");
	size_t position1 = expr.find("sqrt:");
	if(position1 != string::npos){
		expr = findSqRoot(expr);
		cout << expr << " this is after findSqRoot" << endl;
	}
	if(position != string::npos){
		expr = findNthRoot(expr);
		cout << expr << " this is after findNthRoot" << endl;
	}
	vector<string> stringVec;
	int count=0;
	for(int i = 0; i < expr.size(); i++){
		if((expr.at(i)=='(')||(expr.at(i)==')')||(expr.at(i)=='+')||(expr.at(i)=='-')||(expr.at(i)=='/')||(expr.at(i)=='*')||(expr.at(i)=='^')){
			stringstream ss;
			if((i-count) != 0){
				//cout << "condition called" << endl;
			stringVec.push_back(expr.substr(count, (i-count)));
			}
			ss << expr.at(i);
			stringVec.push_back(ss.str());
			ss.str("");
			count = i+1;
		}
	}
	if(count < expr.size()){
		//cout << "is called" << endl;
		stringVec.push_back(expr.substr(count, (expr.size()-1)));
	}
	for(int i = 0; i < stringVec.size(); i++){
		cout << stringVec[i]<<" this is the index of toString method"<< endl;
	}
	return stringVec;
}

/* The shuntYard method takes in a user defined string and sorts it in order of operations. It returns the string as
a vector that is sorted into Reverse Polish notation, making the expression able to be solved. This takes PEMDAS into 
account.
*/
vector<string> shuntYard(string x) {
	vector<string> expr = toStringVec(x);
	for(int i = 0; i < expr.size(); i++){
		string s = expr[i];
		cout << s << endl;
	}
	vector<string> queue;  stack<char> opStack;
	map<char, int> opPrec;
	opPrec['('] = -1;
	opPrec['+'] = 1; opPrec['-'] = 1;
	opPrec['*']  = 2; opPrec['/']  = 2;
	opPrec['^']  = 3; opPrec['sqrt']  = 3;
	bool lastWasOp = true;
	for(int i=0;i<expr.size();i++){
		if((expr[i]=="+")||(expr[i]=="-")||(expr[i]=="/")||(expr[i]=="*")||(expr[i]=="^")||(expr[i]=="(")||(expr[i]==")")){
			switch (expr[i].at(0)) {
		    case '(':
		      opStack.push('(');
		      break;
		    case ')':
		      while ((!opStack.empty() && (opStack.top() != '('))) {
				stringstream ss;
		      	ss<<opStack.top();
		        queue.push_back(ss.str());
		        opStack.pop();
			  }
			  if(opStack.empty()){
					throw domain_error(
							"Unrecognized unary operator.");
					}
			  	opStack.pop();
		      break;
		    default:  //op precedence
		      	{
		        if (lastWasOp) {
		          // Convert unary operators to binary in the RPN.
		          if (expr[i]=="-" || expr[i]=="+") {
		            queue.push_back("0");
		          } 
				  else {
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
	for(int i = 0; i < queue.size(); i++){
		cout << queue[i]; }
		cout << endl;
		cout << "This is the RPN notation above" << endl;
	return queue;
}

/*Menu accessed by user- in order to compute a new expression, the user needs to select the first option and then type the expression
as they would normally. */ 
void menu(){

	Calculator calc = Calculator();
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
			//input = findNthRoot(input);

			try{ 
				vector<string> conv = shuntYard(input); 
				vector<Input*> converted = conversion2(conv);
				calc.setVec(converted);
				if(calc.solve() == false){
				cout << "An error has occurred." << endl;
				}
				cout << endl;
			}
			catch(domain_error){
				cout << "Unrecognized order of operators." << endl;
			}
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
				cout << "You may NOT have a space between a pair of operators, numbers, or operator-number pair." << endl;
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

return 0;
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
//}
