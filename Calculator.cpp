#include "Calculator.h"
#include <string>
using namespace std;


class dividebyzero: public exception
{
  virtual const char* what() const throw()
  {
    return "Cannot divide by zero";
  }
} nullzero;

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
	//Rational* res1 = (Rational*)res;
	//cout<< typeid(*res).name()<<endl;
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
void Calculator::ansParse(string& y) {
    size_t check = y.find("Ans");
    size_t check2 = y.find("ans");
    size_t position = 0;
    if(check != string::npos) {
        position = check;
    }
    else if(check2 != string::npos) {
        position = check2;
    }
	while(position != string::npos){
    stringstream ss;
    for(int i = 0; i < position; i++) {
        ss << y.at(i);
    }
    ss << getlastAns();
    for(int i = position + 3; i< y.size(); i++) {
        ss << y.at(i);
    }
    y = ss.str();
	}
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
	// string one = typeid(*RPNVec[index]).name();
	// string two = typeid(*RPNVec[index + 1]).name();
	else if((typeid(*RPNVec[index]) == typeid(Rational)) && (typeid(*RPNVec[index + 1]) == typeid(Rational))){
		// cout<< typeid(*RPNVec[index]).name()<<endl;
		// cout<< typeid(*RPNVec[index+1]).name()<<endl;
		Rational* first = (Rational*)RPNVec[index]; ///BUG RIGHT HERE
		Rational* second = (Rational*)RPNVec[index + 1];
		Rational* res = first->add(second);
		res->Simplify();
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
	else if((typeid(*RPNVec[index]) == typeid(Rational)) && (typeid(*RPNVec[index + 1]) == typeid(Rational))){
		Rational* ratfirst = (Rational*)RPNVec[index]; ///BUG RIGHT HERE
		Rational* ratsecond = (Rational*)RPNVec[index + 1];
		Rational* res = ratfirst->subtract(ratsecond);
		res->Simplify();
		RPNVec = rewriteVec(index, res);
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
			result = -1;
			throw nullzero;
		}
		else if (number2 != 0){
			result = number1 / number2;
		}
		if(number1%number2==0){
			Integer* res = new Integer(result);
			RPNVec = rewriteVec(index,res);
		}
		else{
			Rational* rat = new Rational(number1, number2);
			rat->Simplify();
			//res->Simplify();
			RPNVec = rewriteVec(index, rat);
			

		}
	}
	else if((typeid(*RPNVec[index]) == typeid(Rational)) && (typeid(*RPNVec[index + 1]) == typeid(Rational))){
		Rational* ratfirst = (Rational*)RPNVec[index]; ///BUG RIGHT HERE
		Rational* ratsecond = (Rational*)RPNVec[index + 1];
		Rational* res = ratfirst->divide(ratsecond);
		res->Simplify();
		RPNVec = rewriteVec(index, res);
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
	else if((typeid(*RPNVec[index]) == typeid(Rational)) && (typeid(*RPNVec[index + 1]) == typeid(Rational))){
		Rational* ratfirst = (Rational*)RPNVec[index]; ///BUG RIGHT HERE
		Rational* ratsecond = (Rational*)RPNVec[index + 1];
		Rational* res = ratfirst->multiply(ratsecond);
		res->Simplify();
		RPNVec = rewriteVec(index, res);
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
			if(typeid(*RPNVec[0])== typeid(Rational)){
				Rational* rat = (Rational*)RPNVec[0];
				ostringstream ss;
				ss<<rat->getNoom() <<"/"<< rat->getDen();
				setAns(ss.str());
			}
			else if(typeid(*RPNVec[0])== typeid(Integer)){
				Integer* ans = (Integer*)RPNVec[0];
				ostringstream ss;
				ss<<ans->getInteger();
				setAns(ss.str());
			}
			printSolution();
			return true;
	}
}
