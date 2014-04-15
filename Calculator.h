/*
Header file for Calculator.cpp. Contains necessary methods to support powers, division, multiplication, and other operations.
It also contains the recursive solve() method that utilizes the operator methods to shrink down the vector, going until
the vector is of size 1.
*/
#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include "Input.h"
#include "Integer.h"
#include "Operator.h"
#include "Rational.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <exception>

using namespace std;

class Calculator{

private:
	vector<Input*> RPNVec; //Global Vector RPNVec
	string lastAns;

public:
	Calculator();
	void setVec(vector<Input*> Vec);
	vector<Input*> rewriteVec(int index, Input* res);
	string getlastAns();
	void setAns(string ans);
	void printSolution();
	bool solve();
	void ansParse(string &y);
	//string addAllToIndex(Input input1, Input input2, Operator operate);
	void add(int index);
	void subtract(int index);
	void divide(int index);
	void multiply(int index);
	void power(int index);
	int ipow(int base, int exp);
	void printSolution();

};
#endif /* CALCULATOR_H_ */