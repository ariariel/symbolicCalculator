#include "Calculator.h"
using namespace std;

//Handling the divide by zero exception
class dividebyzero: public exception
{
  virtual const char* what() const throw()
  {
    return "Cannot divide by zero";
  }
} nullzero;


//Default Constructor
Calculator::Calculator(){
	vector<Input*> RPNVec;
	lastAns;
}

/*
getlastAns() returns the user's lastAns.
*/
string Calculator::getlastAns(){
	return lastAns;
}

/*
setAns sets the lastAns for the user.
*/
void Calculator::setAns(string ans){
	this->lastAns = ans;
}

/*
Sets the vector as a global vector
*/
void Calculator::setVec(vector<Input*> Vec){
	RPNVec = Vec;
}

/*
rewriteVec is responsible for shrinking the vector down to one value, returning a definite answer. It is called in the 
operator methods.
*/
vector<Input*> Calculator::rewriteVec(int index, Input* res){
	vector<Input*> result;
	for(int i =0; i<index; i++){
		result.push_back(RPNVec[i]);
	}
	result.push_back(res);
	for(int i =index+1; i<RPNVec.size()-2; i++){
		result.push_back(RPNVec[i+2]);
	}
	return result;
}


// string Calculator::addAllToIndex(Input input1, Input input2, Operator operate, vector<Input> &RPNVec){
// 	ostringstream str;
// 	if(typeid(input1) == typeid(Integer)){
// 	str << input1.getInteger();
// 	}
// 	else if(typeid(input1) == typeid(Rational)){
// 	str << input1.getRational();
// 	}
// 	else if(typeid(input1) == typeid(Irrational)){
// 	str << input1.getIrrational();
// 	}

// 	if(typeid(operate) == typeid(Operator)){
// 		str << operate.getOperand();
// 	}

// 	if(typeid(input2) == typeid(Integer)){
// 	str << input1.getInteger();
// 	}
// 	else if(typeid(input2) == typeid(Rational)){
// 	str << input2.getRational();
// 	}
// 	else if(typeid(input2) == typeid(Irrational)){
// 	str << input2.getIrrational();
// 	}
// 	return str.str();
// }

/*
Add method that takes in the index of the vector and adds that value with the value next to it in the index.
It then calls the rewriteVec method, which shrinks the vector down two elements.
*/
void Calculator::add(int index){
	int result;
	if((typeid(*RPNVec[index]) == typeid(Integer)) && (typeid(*RPNVec[index + 1]) == typeid(Integer))){
		Integer* first = (Integer*)RPNVec[index];
		int number1 = first->getInteger();
		Integer* second = (Integer*)RPNVec[index + 1];
		int number2 = second->getInteger();
		result = number1 + number2;
		Integer* res = new Integer(result);
		RPNVec = rewriteVec(index, res);
	}
	// else{ 
	// 	 // Input* input1 = RPNVec[index];
	// 	 // Input* input2 = RPNVec[index + 1];
	// 	 // Input* input3 = RPNVec[index + 2];
	// 	 // string result = addAllToIndex(input1, input2, input3, RPNVec);
	// }
	//  RPNVec[index] = new Integer(result);
	//  RPNVec.erase(RPNVec.begin() + index);
	//  RPNVec.erase(RPNVec.begin() + (index+1));

 // 	for(int i = 0; i < RPNVec.size(); i++){
 // 		Integer* test = (Integer*)RPNVec[i];
	// 	cout << test->getInteger();
	// }

}

/*
Subtract method that takes in the index of the vector and subtracts that value with the value next to it in the index.
It then calls the rewriteVec method, which shrinks the vector down two elements.
*/
void Calculator::subtract(int index){
	int result;
	if((typeid(*RPNVec[index]) == typeid(Integer)) && (typeid(*RPNVec[index + 1]) == typeid(Integer))){
		Integer* first = (Integer*)RPNVec[index];
		int number1 = first->getInteger();
		Integer* second = (Integer*)RPNVec[index + 1];
		int number2 = second->getInteger();
		result = number1 - number2;
		Integer* res = new Integer(result);
		RPNVec = rewriteVec(index,res);
	}
}

/*
Divide method that takes in the index of the vector and divides that value with the value next to it in the index.
It then calls the rewriteVec method, which shrinks the vector down two elements. It also takes into account rational
numbers.
*/
void Calculator::divide(int index){
	int result;
	if((typeid(*RPNVec[index]) == typeid(Integer)) && (typeid(*RPNVec[index + 1]) == typeid(Integer))){
		Integer* first = (Integer*)RPNVec[index];
		int number1 = first->getInteger();
		Integer* second = (Integer*)RPNVec[index + 1];
		int number2 = second->getInteger();
		if (number2 == 0){
			result = -1;
			throw nullzero;
		}
		else if (number2 != 0){
			result = number1 / number2;
		}
		if(typeid(result)==typeid(1)){
			Integer* res = new Integer(result);
			RPNVec = rewriteVec(index,res);
		}
		else if(typeid(result)==typeid(0.5)){
			Rational* res = new Rational(number1, number2);
			res->Simplify();
			RPNVec = rewriteVec(index, res);

		}
	}
}

/*
Multiply method that takes in the index of the vector and multiplies that value with the value next to it in the index.
It then calls the rewriteVec method, which shrinks the vector down two elements.
*/
void Calculator::multiply(int index){
	int result;
	if((typeid(*RPNVec[index]) == typeid(Integer)) && (typeid(*RPNVec[index + 1]) == typeid(Integer))){
		Integer* first = (Integer*)RPNVec[index];
		int number1 = first->getInteger();
		Integer* second = (Integer*)RPNVec[index + 1];
		int number2 = second->getInteger();
		result = number1 * number2;
		Integer* res = new Integer(result);
		RPNVec = rewriteVec(index,res);
	}
}

/*
Power method that takes in the index of the vector and takes the power of that value next to it in the index.
It then calls the rewriteVec method, which shrinks the vector down two elements.
*/
void Calculator::power(int index){
	int result;
	if((typeid(*RPNVec[index]) == typeid(Integer)) && (typeid(*RPNVec[index + 1]) == typeid(Integer))){
		Integer* first = (Integer*)RPNVec[index];
		int number1 = first->getInteger();
		Integer* second = (Integer*)RPNVec[index + 1];
		int number2 = second->getInteger();
		result = ipow(number1, number2);
		Integer* res = new Integer(result);
		RPNVec = rewriteVec(index,res);
	}
}

//Helper method for power method
int Calculator::ipow(int base, int exp){
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

/*
printSolution aids in the printing of rational and integer numbers to the screen as an answer.
*/
void Calculator::printSolution(){
	if(typeid(*RPNVec[0]) == typeid(Integer)){
		Integer* num = (Integer*)RPNVec[0];
		cout << num->getInteger() << endl;
	}
	else if(typeid(*RPNVec[0]) == typeid(Rational)){
		Rational* rat = (Rational*)RPNVec[0];
		cout << rat->getNoom() << "/" << rat->getDen() << endl;
	}
}

/*
Recursive method solve that checks to see what operation is in the vector. If the operation matches, then it performs the
respective operation, shrinking the vector down to size.
*/
bool Calculator:: solve(){ 

	for(int i = 0; i<RPNVec.size(); i++){
		if(typeid(*RPNVec[i]) == typeid(Operator)){
			Operator* opObject = (Operator*)RPNVec[i];
			char op = opObject->getOperand();
			switch(op){
				case '+': add(i-2);
						return solve();
				case '-': subtract(i-2);
						return solve();
				case '/': divide(i-2);
						return solve();
				case '*': multiply(i-2);
						return solve();
				case '^': power(i-2);
						return solve();
			}
		}
	}
	if(RPNVec.size() == 1){

			Integer* b = (Integer*)RPNVec[0];
			int num = b->getInteger();
			cout << num << endl;
			cout<< "SOLVED!" << endl;
			return true;
	}
}
