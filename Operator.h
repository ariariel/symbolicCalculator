#ifndef OPERATOR_H_
#define OPERATOR_H_
#include "Calculator.h"
#include "Input.h"
#include <iostream>
using namespace std;

class Operator: public Input{

private:
	char operand;

public:
	Operator():Input(){

	}

	Operator(char operand){ //need a default or initialization constructor?
		this->operand = operand;
		cout<< "OPERATOR OBJECT CREATED" << endl;
	}

	virtual char getOperand(){
		return operand;
	} 
};

#endif OPERATOR_H_