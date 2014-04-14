// .h
//Rational class header
#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <iostream>
#include <stdexcept>

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

  Rational add(Rational rat){

  }

};
#endif 




