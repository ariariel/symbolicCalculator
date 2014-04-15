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
  Rational( int num, int den )
  {
     this->Numerator=num;
     this->Denominator = den;
    // if(this->Denominator == 0)
    // {
    //   throw overflow_error("cannot have 0 as a demoninator");
    // }
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
  void Simplify()
  {
          int GCDNumber = GCD();

          if(GCDNumber != 0)
          {
                  Numerator = Numerator / GCDNumber;
                  Denominator = Denominator / GCDNumber;
          }
          else{
            cout<< ""<< endl;
          }
  }

  Rational* add(Rational* rat){
      int noom0 = this->Numerator;
      int den0 = this->Denominator;
      int den1 =rat->getDen();
      int noom1 = rat->getNoom();

      int newNoom = (noom0 * den1) + (den0 * noom1);
      int newDen = den0*den1;
      return new Rational(newNoom, newDen);
  }
  Rational* subtract(Rational* rat){
      int noom0 = this->Numerator;
      int den0 = this->Denominator;
      int den1 =rat->getDen();
      int noom1 = rat->getNoom();

      int newNoom = (noom0 * den1) - (den0 * noom1);
      int newDen = den0*den1;
      return new Rational(newNoom, newDen);
  }
    //Multiply method for rational
  Rational* multiply(Rational* rat){
      int Numerator1 = this->Numerator;
      int Denominator1 = this->Denominator;
      int Numerator2 = rat->getNoom();
      int Denominator2 = rat->getDen();
      int finalNumerator = Numerator1 * Numerator2;
      int finalDenominator = Denominator1 * Denominator2;
      Rational* finalRat = new Rational(finalNumerator, finalDenominator);
      return finalRat;
  }

  //Divide method for rational
  Rational* divide(Rational* rat){
    int Numerator1 = this->Numerator;
    int Denominator1 = this->Denominator;
    int Numerator2 = rat->getNoom();
    int Denominator2 = rat->getDen();
    int finalNumerator = Numerator1 * Denominator2;
    int finalDenominator = Denominator1 * Numerator2;
    Rational* finalRat = new Rational(finalNumerator, finalDenominator);
    return finalRat;
  }

};
#endif 




