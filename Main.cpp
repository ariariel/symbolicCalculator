
#include <iostream>
#include <sstream>
#include "Calculator.h"
#include "Input.h"

using namespace std;

void menu();
string AnsParse(string input);
string RootToPower(string input);
string shuntYardAlg(string input);

int main(){

	menu();


return 0;
}

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
	cout << "2: Get Previous Answer" << endl;
	cout << "3: Help" << endl;
	cout << "4: Quit" << endl;
	cout << endl;

	cin >> userInput;
	cout << endl;

		if(userInput == "1"){
		    string input;
			char keepRun = 'y';
			while(keepRun){
			cout << "Please type in the expression you wish to solve." << endl;
			cout << "Note: When inputting roots of an expression, please insert them in an exponential form." << endl;
			cout << "To exit this option, type 'back' or 'quit'." << endl;
			cout << endl;
			cin >> input;
			cout << endl;
			if(input == "back" || input == "Back" || input == "Quit" || input == "quit"){
				break;
			}
			//ShuntYardAlg(user);
			//call the necessary methods in order to put into RPN method, conversion, and solve. Or will ShuntYardAlg call these
			//methods for us?
			}
		}

		else if(userInput == "2"){
			//using the object name and calling the getPrevAns Method
			//Calculator calc = new Calculator();
			//calc.getPrevAns();
		}

		else if(userInput == "3"){
			string helpinput;
			char keepItRunning = 'y';
			while(keepItRunning){
				cout << "Welcome to the help screen." << endl;
				cout << "Please pick the query that your question relates to." << endl;
				cout << "1: Operator Syntax" << endl;
				cout << "2: Fundamentals of Using This Calculator" << endl;
				cout << "3: Limits on Functionality" << endl;
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
				cout << "The nth root of x: x^(1/n) (where 'n' is replaced by a number)" << endl;
				cout << "Log base b of x: log_b:x" << endl;
			}

			else if(helpinput == "2"){
			}

			else if(helpinput == "3"){
				cout << "This program supports the following number types: " << endl;
				cout << "Integers (whole numbers), rational numbers (fractions), pi, e, and nth-root irrationals. " << endl;
				cout << "The program also supports exponentials. However, this doesn't include x^pi or x^e. " << endl;
				cout << "For multiplication using irrationals, please add a multiplication sign between the symbols." << endl;
				cout << "When subtracting a negative element, please use parenthesis to separate the postive and negative number." << endl;
				cout << "You must NOT have a space between a pair of operators, numbers, or operator-number pair." << endl;
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

		else if(userInput == "4"){
			break;
		}

		else {
			cout << "Please choose one of the specified options." << endl;
			cout << endl;
		}
	}
}

string AnsParse(string input){
	return input;
}

string RootToPower(string input){
	return input;
}

string shuntYardAlg(string input){
	return input;
}