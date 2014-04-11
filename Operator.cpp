#include "Operator.h"
#include "Integer.h"


Operator::Operator(){

}

Operator::Operator(char operand){ //need a default or initialization constructor?
	this->operand = operand;
}

char Operator::getOperand(){
	return operand;
} 

void Operator::add(int index, vector<Input> &RPNVec){
	int result;
	if((typeid(RPNVec[index]) == typeid(Integer)) && (typeid(RPNVec[index + 1]) == typeid(Integer))){
		int number1 = RPNVec[index]; //Error here: no suitable conversion from "Input" to "int" exists
		//do we need another conversion method that changes to int?
		int number2 = RPNVec[index + 1];
		result = number1 + number2;
		RPNVec[index] = result;
	}
	else{
		 Input input = RPNVec[index];
		 Input input2 = RPNVec[index + 1];
		 //how to combine two Input values and store into the same index?
	}
	RPNVec.erase(RPNVec.begin() + 1);
	//delete second, third elements
	//make a simpler vector
	//if is irrational, then return the same and move on in the vector
	}

void Operator::subtract(int index){

}

void Operator::multiply(int index){

}

void Operator::divide(int index){

}

void Operator::power(int index){

}