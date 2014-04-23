// .h
//Rational class header
#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <iostream>
#include <stdexcept>
#include "Input.h"

using namespace std;

/*
Rational is the subclass of Input. It is used to represent fractions.
*/

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

  /*
  GetNumerator method that returns the rational's respective numerator.
  */
  int getNoom(){
    return Numerator;
  }

  /*
  setNoom method that initializes the numerator to a user defined value.
  */
  void setNoom(int num){
    this->Numerator = num;
  }

  /*
  getDen method that returns the rational's respective denominator.
  */
  int getDen(){
    return Denominator;
  }

  /*
  setDen method that initializes the denominator to a user defined value.
  */
  void setDen(int den){
    this->Denominator = den;
  }

  Rational* add(Rational* rat){
      int noom0 = this->getNoom();
      int den0 = this->getDen();
      int den1 =rat->getDen();
      int noom1 = rat->getNoom();

      int newNoom = (noom0 * den1) + (den0 * noom1);
      int newDen = den0*den1;
      return new Rational(newNoom, newDen);
  }
  Rational* subtract(Rational* rat){
      int noom0 = this->getNoom();
      int den0 = this->getDen();
      int den1 =rat->getDen();
      int noom1 = rat->getNoom();

      int newNoom = (noom0 * den1) - (den0 * noom1);
      int newDen = den0*den1;
      return new Rational(newNoom, newDen);
  }
    //Multiply method for rational
  Rational* multiply(Rational* rat){
      int Numerator1 = this->getNoom();
      int Denominator1 = this->getDen();
      int Numerator2 = rat->getNoom();
      int Denominator2 = rat->getDen();
      int finalNumerator = Numerator1 * Numerator2;
      int finalDenominator = Denominator1 * Denominator2;
      //Rational* finalRat = new Rational(finalNumerator, finalDenominator);
      //return finalRat;
      return new Rational(finalNumerator, finalDenominator);
  }

  Rational* pow(int numb){
	int Numer = this->getNoom();
	int Denom = this->getDen();
	int NewNoom = powHelper(Numer, numb);
	int NewDen = powHelper(Denom, numb);
		return new Rational(NewNoom, NewDen);
  
  }

  int Rational::powHelper(int base, int exp){
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

  //Divide method for rational
  Rational* divide(Rational* rat){
    int Numerator1 = this->getNoom();
    int Denominator1 = this->getDen();
    int Numerator2 = rat->getNoom();
    int Denominator2 = rat->getDen();
    int finalNumerator = Numerator1 * Denominator2;
    int finalDenominator = Denominator1 * Numerator2;
    //Rational* finalRat = new Rational(finalNumerator, finalDenominator);
    //return finalRat;
      return new Rational(finalNumerator, finalDenominator);
  }

  /*
  Helper method for simplify()
  */
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

  /*
  Simplify the rational number to its smallest form
  */
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
