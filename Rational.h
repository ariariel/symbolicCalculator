// .h
//Rational class header
#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <iostream>
#include <stdexcept>
#include "Input.h"

using namespace std;



class Rational: public Input
{
private:

  int Numerator;
  int Denominator;

public:

  // Construct rational from numerator and denominator
  Rational(int num, int den)
  {
     this->Numerator=num;

    if (Denominator == 0)
    {
      throw overflow_error("cannot have 0 as a demoninator");
    }
    else
    {
      this->Denominator = den;
    }
  }
  int getNoom(){
    return Numerator;
  }
  void setNoom(int num){
    this->Numerator = num;
  }
  int getDen(){
    return Denominator;
  }
  void setDen(int den){
    this->Denominator = den;
  }

  //Multiply method for rational
  Rational multiply(Rational* rat){
	    int Numerator1 = this->Numerator;
		int Denominator1 = this->Denominator;
		int Numerator2 = rat->getNoom();
		int Denominator2 = rat->getDen();
		int finalNumerator = Numerator1 * Numerator2;
		int finalDenominator = Denominator1 * Denominator2;
		Rational finalRat = Rational(finalNumerator, finalDenominator);
		finalRat.Simplify();
		return finalRat;
  }

  //Divide method for rational
  Rational divide(Rational* rat){
		int Numerator1 = this->Numerator;
		int Denominator1 = this->Denominator;
		int Numerator2 = rat->getNoom();
		int Denominator2 = rat->getDen();
		int finalNumerator = Numerator1 * Denominator2;
		int finalDenominator = Denominator1 * Numerator2;
		Rational finalRat = Rational(finalNumerator, finalDenominator);
		finalRat.Simplify();
		return finalRat;
  }

  int GCD()
  {
          int A = Numerator;
          int B = Denominator;

          int Temp;

          while(B)
          {
                  Temp = B;
                  B = A%B;
                  A = Temp;
          }

          return A;
  }
  //Simplify the rational number to its smallest form
  void Simplify(){ 
	  int GCDNumber = GCD();
          if(GCDNumber != 0)
          {
                  Numerator = Numerator / GCDNumber;
                  Denominator = Denominator / GCDNumber;
          }
          else{
            cout<< "" << endl;
          }
  }
};
#endif 




