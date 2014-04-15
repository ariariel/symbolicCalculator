#ifndef OPERATOR_H_
#define OPERATOR_H_
#include "Calculator.h"
#include "Input.h"
#include <iostream>
using namespace std;

/*
Class Operator is a subclass of Input. It is used to represent operations, which include /, *, +, -, and ^.
*/
class Operator: public Input{

private:
	char operand;

public:

	//Default constructor
	Operator():Input(){
	}

	//Initialization constructor
	Operator(char operand){
		this->operand = operand;
	}

	//getOperand returns the necessary operand.
	virtual char getOperand(){
		return operand;
	} 
};

#endif OPERATOR_H_