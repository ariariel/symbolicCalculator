#ifndef IRRATIONAL_H_
#define IRRATIONAL_H_

#include "Input.h"
#include "Calculator.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Irrational: public Input{

private:
	string irrational;

public:
	//Default Constructor
	Irrational(){
	}

	//Initialization Constructor
	Irrational(string irrational){
		this->irrational = irrational;
	}

	//getIrrational method
	virtual string getIrrational(){
		return irrational;
	}

	string add(string expression){
		//create stringstream variable to store each number in it and recreate the irrational! Then access the rest of the exp
		//and parse it into the answer so it's in one vector
		
	return "";
	}

	string subtract(string expression){
	return "";
	}

	string multiply(string expression){
	return "";
	}

	string divide(string expression){
	return "";
	}

	int gcd(){
	return 0;
	}
};

#endif /* IRRATIONAL_H_ */