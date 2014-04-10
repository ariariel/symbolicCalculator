#include <cmath>
#include <iostream>
using namespace std; 

int index1;
int index2;
char operand;
string s;


cin >> operand >> endl;

if( operand == '+'){
	add(index1, index2);
}
else if ( operand == '-' ){
	subtract(index1, index2);
}
else if ( operand == '*'){
	multiply(index1, index2);
}
else if ( operand == '/'){
	divide(index1, index2);
}
else if ( operand == '^'){
	power(index1, index2);
}

cin >> index1 >> endl;
cin >> index2 >> endl;

void add(index1, index2){
	sum = index1 + index2;
}
void subtract(index1, index2){
	difference = index1 - index2;
}
void multiply(index1, index2){
	product = index1 * index2;
}
void divide(index1, index2){
	quotient = index1 / index2;
}
string power(index1, index2){
	s = pow(index1, index2);
	return s;
}
