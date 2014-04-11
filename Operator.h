#ifndef OPERATOR_H_
#define OPERATOR_H_
#include "Calculator.h"
#include "Input.h"
#include <cmath>

class Operator: public Input{

private:
	char operand;

public:
	Operator();
	Operator(char operand);
	char getOperand();
	void add(int index, vector<Input> &RPNVec);
	void subtract(int index);
	void multiply(int index);
	void divide(int index);
	void power(int index);


};
#endif /* OPERATOR_H_ */