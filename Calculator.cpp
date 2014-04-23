#include "Calculator.h"
#include <cmath>
#include <string>
using namespace std;

Calculator::Calculator(){
	vector<Input*> RPNVec;
	lastAns;
}
string Calculator::getlastAns(){
	return lastAns;
}
void Calculator::setAns(string ans){
	this->lastAns = ans;
}


void Calculator::setVec(vector<Input*> Vec){
	RPNVec = Vec;
}

vector<Input*> Calculator::rewriteVec(int index, Input* res){
	if(typeid(res) == typeid(Rational)){
		Rational* res1 = (Rational*) res;
	}
	else if(typeid(res) == typeid(Integer)){
		Integer* res1 = (Integer*) res;
	cout << res1->getInteger() << "this is the input for res"<< endl;
	}

	cout << index << "this is the index" << endl;
	vector<Input*> result;
	for(int i =0; i<index; i++){
		result.push_back(RPNVec[i]);
	}
	result.push_back(res);
	for(int i =index+1; i<RPNVec.size()-2; i++){
		result.push_back(RPNVec[i+2]);
	}

	//cout << "This is the rewritevec method." << endl;
	//for(int i = 0; i < result.size(); i++){
	//Integer* numb = (Integer*)result[i];
	//Rational* numb = (Rational*)result[i];
	//cout << numb->getInteger() << "Index i of the vec" << endl;
	//cout << numb->getNoom() << "Numerator" << numb->getDen() << "Denom" << endl;
	//}
	return result;
}

void Calculator::ansParse(string& y) {
    size_t check = y.find("Ans");
    size_t check2 = y.find("ans");
    size_t position = 0;
    if(check != string::npos) {
        position = check;
    }
    else if(check2 != string::npos) {
        position = check2;
    }
	while(position != string::npos){
    stringstream ss;
    for(int i = 0; i < position; i++) {
        ss << y.at(i);
    }
    ss << getlastAns();
    for(int i = position + 3; i< y.size(); i++) {
        ss << y.at(i);
    }
    y = ss.str();
	}
}

void Calculator::add(int index){
	int result;
	
	if((typeid(*RPNVec[index]) == typeid(Integer)) && (typeid(*RPNVec[index + 1]) == typeid(Integer))){
		Integer* first = (Integer*)RPNVec[index];
		int number1 = first->getInteger();
		Integer* second = (Integer*)RPNVec[index + 1];
		int number2 = second->getInteger();
		result = number1 + number2;
		cout << result <<" this is the result of the addition" << endl;
		Integer* res = new Integer(result);
		RPNVec = rewriteVec(index, res);
	}
	else if((typeid(*RPNVec[index]) == typeid(Rational)) && (typeid(*RPNVec[index + 1]) == typeid(Rational))){
		Rational* first = (Rational*)RPNVec[index];
		Rational* second = (Rational*)RPNVec[index + 1];
		Rational* res = first->add(second);
		res->Simplify();
		RPNVec = rewriteVec(index, res);
	}
	else if(((typeid(*RPNVec[index]) == typeid(Rational)) && (typeid(*RPNVec[index + 1]) == typeid(Integer)))){
		cout << "are you seeing this?";
		Rational* first = (Rational*)RPNVec[index];
		Integer* second = (Integer*)RPNVec[index+1];
		Rational* num = new Rational(second->getInteger(), 1);
		Rational* res = first->add(num);
		res->Simplify();
		RPNVec = rewriteVec(index, res);
	
	}
	else if(((typeid(*RPNVec[index]) == typeid(Integer)) && (typeid(*RPNVec[index + 1]) == typeid(Rational)))){
		Integer* first = (Integer*)RPNVec[index];
		Rational* second = (Rational*)RPNVec[index+1];
		Rational* num = new Rational(first->getInteger(), 1);
		Rational* res = num->add(second);
		res->Simplify();
		RPNVec = rewriteVec(index, res);
	}
}
void Calculator::subtract(int index){
	int result;
	if((typeid(*RPNVec[index]) == typeid(Integer)) && (typeid(*RPNVec[index + 1]) == typeid(Integer))){
		Integer* first = (Integer*)RPNVec[index];
		int number1 = first->getInteger();
		Integer* second = (Integer*)RPNVec[index + 1];
		int number2 = second->getInteger();
		result = number1 - number2;
		Integer* res = new Integer(result);
		RPNVec = rewriteVec(index,res);
	}
	else if((typeid(*RPNVec[index]) == typeid(Rational)) && (typeid(*RPNVec[index + 1]) == typeid(Rational))){
		Rational* ratfirst = (Rational*)RPNVec[index];
		Rational* ratsecond = (Rational*)RPNVec[index + 1];
		Rational* res = ratfirst->subtract(ratsecond);
		res->Simplify();
		RPNVec = rewriteVec(index, res);
	}
	else if(((typeid(*RPNVec[index]) == typeid(Rational)) && (typeid(*RPNVec[index + 1]) == typeid(Integer)))){
		Rational* first = (Rational*)RPNVec[index];
		Integer* second = (Integer*)RPNVec[index+1];
		Rational* num = new Rational(second->getInteger(), 1);
		Rational* res = first->subtract(num);
		res->Simplify();
		RPNVec = rewriteVec(index, res);
	
	}
	else if(((typeid(*RPNVec[index]) == typeid(Integer)) && (typeid(*RPNVec[index + 1]) == typeid(Rational)))){
		Integer* first = (Integer*)RPNVec[index];
		Rational* second = (Rational*)RPNVec[index+1];
		Rational* num = new Rational(first->getInteger(), 1);
		Rational* res = num->subtract(second);
		res->Simplify();
		RPNVec = rewriteVec(index, res);
	}
}
void Calculator::divide(int index){
	int result = 0;
	if((typeid(*RPNVec[index]) == typeid(Integer)) && (typeid(*RPNVec[index + 1]) == typeid(Integer))){
		Integer* first = (Integer*)RPNVec[index];
		int number1 = first->getInteger();
		cout << number1<<" the following is the first number" << endl;
		Integer* second = (Integer*)RPNVec[index + 1];
		int number2 = second->getInteger();
		cout << number2 << " the following is the second number" << endl;
		if (number2 == 0){
			cout << "Cannot divide by zero" << endl;
			result = -1;
		}
		else if ((number1 >= number2)){
			result = number1 / number2;
		}
		if(number1 % number2 == 0){
			Integer* res = new Integer(result);
			RPNVec = rewriteVec(index,res);
		}
		else{
			Rational* rat = new Rational(number1, number2);
			rat->Simplify();
			cout << rat->getNoom() << "<<<This is the numerator" << rat->getDen() << " <<<This is the denom" << endl;
			RPNVec = rewriteVec(index, rat);
		}
	}
	else if((typeid(*RPNVec[index]) == typeid(Rational)) && (typeid(*RPNVec[index + 1]) == typeid(Rational))){
		Rational* ratfirst = (Rational*)RPNVec[index];
		Rational* ratsecond = (Rational*)RPNVec[index + 1];
		Rational* res = ratfirst->divide(ratsecond);
		res->Simplify();
		RPNVec = rewriteVec(index, res);
	}
	else if(((typeid(*RPNVec[index]) == typeid(Rational)) && (typeid(*RPNVec[index + 1]) == typeid(Integer)))){
		Rational* first = (Rational*)RPNVec[index];
		Integer* second = (Integer*)RPNVec[index+1];
		Rational* num = new Rational(second->getInteger(), 1);
		Rational* res = first->divide(num);
		res->Simplify();
		RPNVec = rewriteVec(index, res);
	
	}
	else if(((typeid(*RPNVec[index]) == typeid(Integer)) && (typeid(*RPNVec[index + 1]) == typeid(Rational)))){
		Integer* first = (Integer*)RPNVec[index];
		Rational* second = (Rational*)RPNVec[index+1];
		Rational* num = new Rational(first->getInteger(), 1);
		Rational* res = num->divide(second);
		res->Simplify();
		RPNVec = rewriteVec(index, res);
	}
}
void Calculator::multiply(int index){
	int result;
	if((typeid(*RPNVec[index]) == typeid(Integer)) && (typeid(*RPNVec[index + 1]) == typeid(Integer))){
		Integer* first = (Integer*)RPNVec[index];
		int number1 = first->getInteger();
		cout << "this is the first number in multiply: " << number1 << endl; 
		Integer* second = (Integer*)RPNVec[index + 1];
		int number2 = second->getInteger();
		cout << "this is the second number in multiply: " << number2 << endl;
		result = number1 * number2;
		cout << "the result: " << result << endl;
		Integer* res = new Integer(result);
		RPNVec = rewriteVec(index,res);
	}
	else if((typeid(*RPNVec[index]) == typeid(Rational)) && (typeid(*RPNVec[index + 1]) == typeid(Rational))){
		Rational* ratfirst = (Rational*)RPNVec[index]; //BUG RIGHT HERE
		Rational* ratsecond = (Rational*)RPNVec[index + 1];
		Rational* res = ratfirst->multiply(ratsecond);
		res->Simplify();
		RPNVec = rewriteVec(index, res);
	}
	else if(((typeid(*RPNVec[index]) == typeid(Rational)) && (typeid(*RPNVec[index + 1]) == typeid(Integer)))){
		Rational* first = (Rational*)RPNVec[index];
		Integer* second = (Integer*)RPNVec[index+1];
		Rational* num = new Rational(second->getInteger(), 1);
		Rational* res = first->multiply(num);
		res->Simplify();
		RPNVec = rewriteVec(index, res);
	
	}
	else if(((typeid(*RPNVec[index]) == typeid(Integer)) && (typeid(*RPNVec[index + 1]) == typeid(Rational)))){
		Integer* first = (Integer*)RPNVec[index];
		Rational* second = (Rational*)RPNVec[index+1];
		Rational* num = new Rational(first->getInteger(), 1);
		Rational* res = num->multiply(second);
		res->Simplify();
		RPNVec = rewriteVec(index, res);
	}
}
void Calculator::power(int index){
	int result;
	if((typeid(*RPNVec[index]) == typeid(Integer)) && (typeid(*RPNVec[index + 1]) == typeid(Integer))){
		Integer* first = (Integer*)RPNVec[index];
		int number1 = first->getInteger();
		Integer* second = (Integer*)RPNVec[index + 1];
		int number2 = second->getInteger();
		result = ipow(number1, number2);
		Integer* res = new Integer(result);
		RPNVec = rewriteVec(index,res);
	}
	else if(((typeid(*RPNVec[index]) == typeid(Integer)) && (typeid(*RPNVec[index + 1]) == typeid(Rational)))){
		Integer* first = (Integer*)RPNVec[index];
		int number1 = first->getInteger();
		Rational* second = (Rational*)RPNVec[index+1];
		int number2 = second->getNoom();
		int number3 = second->getDen();
		cout << number2 << " is the numerator for the power" << endl;
		cout << number3 << " is the denominator for the power" << endl;
		double ans = pow((double) number1, 1.0/number3);
		//double ans2 = pow((double) number1, number3);
		cout << ans << "This is the DOUBLE answer for the calculation." << endl;
		int ansRounded = (int)ans;
		double roundResult = (double)ans - (double)ansRounded;
		cout << roundResult << "this is the round result." << endl;
		cout << " <<<< This is the difference in result between the unrounded and rounded answers." << endl;
			if(roundResult == 0){
				result = ansRounded;
				Integer* res = new Integer(result);
				RPNVec = rewriteVec(index, res);
			}
			else if(roundResult > 0.99){
				result = ansRounded + 1;
				Integer* res = new Integer(result);
				RPNVec = rewriteVec(index, res);
			}
			//else if() //if the number is a rational, then return it as a rational number
			
			else{ //if result is a decimal, return it as the original number
				Irrational* res = new Irrational(); //need to know what to put in here as a parameter! Need the entire expression.
				//call res.simplify(), puts in acceptable form
				//then will rewrite all to one index
				RPNVec = rewriteVec(index, res);
		}
	}

	else if(((typeid(*RPNVec[index]) == typeid(Rational)) && (typeid(*RPNVec[index + 1]) == typeid(Rational)))){

		Rational* first = (Rational*)RPNVec[index];
		int num1 = first->getNoom();
		int den1 = first->getDen();
		Rational* second = (Rational*)RPNVec[index+1];
		int num2 = second->getNoom();
		int den2 = second->getDen();
		double ans = pow((double) num1, (double) num2/den2);
		int ansRounded = (int)ans;
		double roundResult = (double)ans - (double)ansRounded;

				if(roundResult > 0.99){
					ansRounded = ansRounded + 1;
				}
		
		double ans2 = pow((double) num2, (double) num2/den2);
		int ansRounded2 = (int)ans;
							cout << roundResult << "this is the round result." << endl;
							cout << " <<<< This is the difference in result between the unrounded and rounded answers." << endl;
				if(roundResult > 0.99){
					ansRounded2 = ansRounded2 + 1;
				}

				Rational* res = new Rational(ansRounded, ansRounded2);
				res->Simplify();
				RPNVec = rewriteVec(index, res);

				//Only works with fractional ints. What if the numerator of the power is greater than 1?



			//else{ //if result is a decimal, return it as the original number
				//Irrational* res = new Irrational(); //need to know what to put in here as a parameter! Need the entire expression.
				//call res.simplify(), puts in acceptable form
				//then will rewrite all to one index
				//RPNVec = rewriteVec(index, res);
		//}

	}

	else if(((typeid(*RPNVec[index]) == typeid(Rational)) && (typeid(*RPNVec[index + 1]) == typeid(Integer)))){
		Rational* first = (Rational*)RPNVec[index];
		Integer* second = (Integer*)RPNVec[index+1];
		int num1 = second->getInteger();
		Rational* res = first->pow(num1);
		res->Simplify();
		RPNVec = rewriteVec(index, res);
	}
}

int Calculator::ipow(int base, int exp){
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

void Calculator::printSolution(){
	if(typeid(*RPNVec[0]) == typeid(Integer)){
		Integer* num = (Integer*)RPNVec[0];
		cout << num->getInteger() << endl;
	}
	else if(typeid(*RPNVec[0]) == typeid(Rational)){
		Rational* rat = (Rational*)RPNVec[0];
		cout << rat->getNoom() << "/" << rat->getDen() << endl;
	}
}

//expression class with expression vector
//have it recursively call toString
//return type input? We want to track the number, not just return a true and print the answer
//fixes lastAns problem
//the i-2 causes an issue with divide, we need to find a way to reimplement solve.
bool Calculator:: solve(){
    
	for(int i = 2; i<RPNVec.size(); i++){
		if(typeid(*RPNVec[i]) == typeid(Operator)){
			Operator* opObject = (Operator*)RPNVec[i];
			char op = opObject->getOperand();
			if(RPNVec.size() == 1){
				break; 
				}
			switch(op){
				case '+': cout<<"the operating symbols are: " << i;
						add(i-2);
						return solve();
				case '-': subtract(i-2);
						return solve();
				case '/': divide(i-2);
						return solve();
				case '*': multiply(i-2);
						return solve();
				case '^': power(i-2);
						return solve();
			}
		}
	}
	if(RPNVec.size() == 1){
			if(typeid(*RPNVec[0])== typeid(Rational)){
				Rational* rat = (Rational*)RPNVec[0];
				ostringstream ss;
				ss<<rat->getNoom() <<"/"<< rat->getDen();
				setAns(ss.str());
			}
			else if(typeid(*RPNVec[0])== typeid(Integer)){
				Integer* ans = (Integer*)RPNVec[0];
				ostringstream ss;
				ss<<ans->getInteger();
				setAns(ss.str());
			}
			cout << "this is the solution" << endl;
			printSolution();
	}
	else if(RPNVec.size() != 1){
		return false;
	}
	return true;
}
