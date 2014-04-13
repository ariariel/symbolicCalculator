#include "Calculator.h"
using namespace std;

Calculator::Calculator(){
	vector<Input*> RPNVec;
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

void Calculator::add(int index, vector<Input*> Vec){
	int result;
	if((typeid(*Vec[index]) == typeid(Integer)) && (typeid(*Vec[index + 1]) == typeid(Integer))){
		Integer* first = (Integer*)Vec[index];
		int number1 = first->getInteger();
		Integer* second = (Integer*)Vec[index + 1];
		int number2 = second->getInteger();
		result = number1 + number2;
		Integer* res = new Integer(result);
		vector<Input*> result;
		for(int i =0; i<index; i++){
			result[i] = Vec[i];
		}
		result.push_back(res);
		for(int i =index+1; i<Vec.size()-2; i++){
			result[i] = Vec[i];
		}
		Vec = result;
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

/* bool Calculator:: solve(){ //need some kind of index as a parameter?
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
*/