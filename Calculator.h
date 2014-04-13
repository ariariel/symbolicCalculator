#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include "Input.h"
#include "Integer.h"
#include "Operator.h"
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Calculator{

private:
	vector<Input*> RPNVec;

public:
	Calculator();
	void setVec(vector<Input*> Vec);
	bool solve();
	//string addAllToIndex(Input input1, Input input2, Operator operate);
	void add(int index);
	void subtract(int index);

};
#endif /* CALCULATOR_H_ */