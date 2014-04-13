#ifndef INTEGER_H_
#define INTEGER_H_
#include "Calculator.h"
#include "Input.h"

class Integer: public Input{

private:
	int value;

public:
	Integer(){

	}
	Integer(int value){
		this->value = value;
		cout<< "INTEGER OBJECT CREATED" << endl;
	}

	virtual int getInteger(){
		return value;
	}


};
#endif /* INTEGER_H_ */