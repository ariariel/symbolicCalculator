// .h
//Rational class header
#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <iostream>

using namespace std;



class Rational: public Input
{
private:

  int Numerator_;
  int Denominator_;

public:

  // Construct rational from numerator and denominator
  Rational( int num, int den )
  {
     this->Numerator_=num;

    if (Denominator_ == 0)
    {
      cout<< "cannot have 0 as a demoninator";
    }
    else
    {
      this->Denominator_ = den;
    }
  }

  int GCD()
  {
          int A = Numerator_;
          int B = Denominator_;

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
                  Numerator_ = Numerator_ / GCDNumber;
                  Denominator_ = Denominator_ / GCDNumber;
          }
          else{
            cout<< ""<< endl;
          }
  }

};
#endif 




