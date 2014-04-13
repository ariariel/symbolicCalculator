#include "Operator.h"
#include "Integer.h"


class Operator: public Input{

private:
	char operand;

public:
	Operator(): Input(){

	}

	Operator(char operand){ //need a default or initialization constructor?
		this->operand = operand;
	}

	char getOperand(){
		return operand;
	} 
};


