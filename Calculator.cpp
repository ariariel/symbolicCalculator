#include "Calculator.h"
using namespace std;

Calculator::Calculator(){
	vector<Input*> RPNVec;
	lastAns;
}
string Calculator::getlastAns(){
	return lastAns;
}
void Calculator::setAns(string ans){
	this->lastAns = ans;
}


void Calculator::setVec(vector<Input*> Vec){
	RPNVec = Vec;
}
vector<Input*> Calculator::rewriteVec(int index, Input* res){
	vector<Input*> result;
	for(int i =0; i<index; i++){
		result[i] = RPNVec[i];
	}
	result.push_back(res);
	for(int i =index+1; i<RPNVec.size()-2; i++){
		result[i] = RPNVec[i];
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
void Calculator::divide(int index){
	int result;
	if((typeid(*RPNVec[index]) == typeid(Integer)) && (typeid(*RPNVec[index + 1]) == typeid(Integer))){
		Integer* first = (Integer*)RPNVec[index];
		int number1 = first->getInteger();
		Integer* second = (Integer*)RPNVec[index + 1];
		int number2 = second->getInteger();
		if (number2 == 0){
			cout << "Cannot divide by zero" << endl;
			result = -1;
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
