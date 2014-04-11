#include "Calculator.h"

Calculator::Calculator(){
	vector<char> RPNVec;
}

bool Calculator:: solve(){ //need some kind of index as a parameter?
	Operator op = Operator();

	if(typeid(RPNVec[i]) == typeid(Operator)){ //need something other than an i to iterate through the vector

		if(RPNVec[i].getOperand() == '+'){
			op.add(RPNVec[i]);
			solve();
		}

		if(RPNVec[i].getOperand() == '-'){
			op.subtract(RPNVec[i]);
			solve();
		}
		
		if(RPNVec[i].getOperand() == '*'){
			op.multiply(RPNVec[i]);
			solve();
		}
		
		if(RPNVec[i].getOperand() == '/'){
			op.divide(RPNVec[i]);
			solve();
		}

		if(RPNVec[i].getOperand() == '^'){
			op.power(RPNVec[i]);
			solve();
		}
	}

	return true;

}