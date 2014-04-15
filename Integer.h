#ifndef INTEGER_H_
#define INTEGER_H_
#include "Calculator.h"
#include "Input.h"
/*
Class Integer is a subclass of Input. It is used to represent whole Integer numbers.
*/
class Integer: public Input{

private:
	int value;

public:
	//Default Constructor
	Integer(){
	}

	//Initialization Constructor
	Integer(int value){
		this->value = value;
	}

	//getInteger method
	virtual int getInteger(){
		return value;
	}

};
#endif /* INTEGER_H_ */