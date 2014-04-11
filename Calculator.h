#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include "Input.h"
#include "Operator.h"
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Calculator{

//protected:
//vector<char> RPNVec;

public:
	vector<char> RPNVec;
	Calculator();
	bool solve();

};
#endif /* CALCULATOR_H_ */