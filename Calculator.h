#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include "Input.h"
#include "Operator.h"
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Calculator{

protected:
	vector<Input> RPNVec;

public:
	Calculator();
	bool solve();
	string addAllToIndex(Input input1, Input input2, Operator operate, vector<Input> &RPNVec);
	void add(int index);

};
#endif /* CALCULATOR_H_ */