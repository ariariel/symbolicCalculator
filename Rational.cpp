// .h
//Rational class header
#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <iostream>

using namespace std;



class Rational
{
  public:

    // Construct rational from numerator and denominator
    Rational( int Numerator_, int Denominator_ );

    static int GCD();

    //Simplify the rational number to its smallest form
    static void Simplify();

    // Return value of numerator
   // int Numerator() const;

    // Return value of denominator
  //  int Denominator() const;




private:

    static int Numerator_;
    static int Denominator_;
    //string Rational; 
};
 
#endif 






//.cpp
#include "Rational.h"
#include <iostream>

using namespace std; 


//constructor for Rational


Rational::Rational( int num, int den )
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


// GCD method

 
int Rational::GCD()
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


//simplifying method

 
void Rational::Simplify()
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



//returns numerator

/*int Rational::Numerator(Numerator_) const
{
        return Numerator_;
}

//returns denominator

int Rational::Denominator(Denominator_) const
{
        return Denominator_;
}
*/

