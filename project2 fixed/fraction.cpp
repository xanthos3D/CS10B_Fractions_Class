/*
   CLASS INVARIANT:

   There are two data members in this class.  "denominator" represents the denominator
   of the Fraction and "numerator" represents the numerator.  Mixed   numbers are
   stored as improper fractions with abs(numerator) > abs(denominator).  Fractions
   are always stored in simplest form with a positive denominator (thus,
   negative fractions will have negative numerators).  Fractions with a
   numerator of 0 always have a denominator of 1.
*/
//xander maniaci, cs10b


#include <iostream>
#include <cmath>
#include <cctype>
#include <cassert>
#include "fraction.h"
#include<cstdlib>
using namespace std;


namespace cs10b_fraction {

    //class implimentation

void Fraction::simplify()
{
    //pre: is called by a public member function and sent a fraction data type by reference.
    //post: simplifys the fraction variable sent to it.
    for(int counter = 2;counter<9999;counter++)
    {
        while(num%counter == 0 && den%counter == 0)
        {
            num /= counter;
            den /= counter;
        }
    }
    if(num == den)
    {
        num = 1;
        den = 1;
    }
    if(den < 0)
    {
        den *= -1;
        num *= -1;
    }
    if(num%den == 0)
    {
        num /=den;
        den = 1;
    }
}

std::ostream& operator << (std::ostream &out, const Fraction printMe)
{
     //pre:obtains a fraction
    //post: prints fraction on screen in proper form.
    if(printMe.den == 1)
  {
      out<<printMe.num;
  }else if(abs(printMe.num)> printMe.den)
  {
      out<<printMe.num/printMe.den<< "+"<< abs(printMe.num % printMe.den) << "/"<< printMe.den;
  }
   else if (printMe.num<printMe.den)
  {
     out<<printMe.num <<"/"<<printMe.den;
  }else if (printMe.num > printMe.den)
  {
      out<<printMe.num/printMe.den<< "+"<< (printMe.num % printMe.den) << "/"<< printMe.den;
  }
  return out;

}
 std::istream& operator >> (std::istream &in, Fraction readMe)
{
    //couldn't get to work. hope you go over this in class at a later date.
    int temp;
    in >> temp;

    if (in.peek() == '+'){

    } else if (in.peek() == '/'){

    } else {

    }


 return in;
}
 //overloaded operations for addition subtraction multiplication and division
Fraction operator + (const Fraction leftOp, const Fraction rightOp)
{
    //pre:obtains a two fractions
    //post: adds fractions and returns result
 Fraction temp;
 temp.num = leftOp.num*rightOp.den + leftOp.den*rightOp.num;
 temp.den = leftOp.den*rightOp.den;
 temp.simplify();
 return temp;
}

Fraction Fraction::operator += (const Fraction rightOp)
{
    //pre:obtains a two fractions
    //post: adds fractions and returns result
 Fraction temp;
 temp = *this + rightOp;
 temp.simplify();
 return  temp;
}

Fraction operator - (const Fraction leftOp, const Fraction rightOp)
{
    //pre:obtains a two fractions
    //post: subtracts fractions and returns result
 Fraction temp;
 temp.num = leftOp.num*rightOp.den - leftOp.den*rightOp.num;
 temp.den = leftOp.den*rightOp.den;
 temp.simplify();
 return temp;
}
Fraction Fraction::operator -= (const Fraction rightOp)
{
    //pre:obtains a two fractions
    //post: subtracts fractions and returns result
 Fraction temp;
 temp = *this - rightOp;
 temp.simplify();
 return  temp;
}

Fraction operator * (const Fraction leftOp, const Fraction rightOp)
{
    //pre:obtains a two fractions
    //post: multiplies fractions and returns result
 Fraction temp;
 temp.num = leftOp.num * rightOp.num;
 temp.den = leftOp.den * rightOp.den;
 temp.simplify();
 return temp;
}
Fraction Fraction::operator *= (const Fraction rightOp)
{
    //pre:obtains a two fractions
    //post: multiplies fractions and returns result
 Fraction temp;
 temp = *this * rightOp;
 temp.simplify();
 return  temp;
}
Fraction operator / (const Fraction leftOp, const Fraction rightOp)
{
    //pre:obtains a two fractions
    //post: divides fractions and returns result
 Fraction temp;
 temp.num = leftOp.num * rightOp.den;
 temp.den = leftOp.den * rightOp.num;
 temp.simplify();
 return temp;
}
Fraction Fraction::operator /= (const Fraction rightOp)
{
    //pre:obtains a two fractions
    //post: divides fractions and returns result
Fraction temp;
 temp = *this / rightOp;
 temp.simplify();
 return  temp;
}
//increment operators
Fraction Fraction::operator ++ ()
{
    //pre:obtains a a fraction by reference
    //post: increment fraction by one in pre or post
    num+=den;
    simplify();
    return *this;

}
Fraction Fraction::operator ++ (int)
{
    //pre:obtains a a fraction by reference
    //post: increment fraction by one in pre or post
    Fraction temp(num,den);
    num+=den;
    simplify();
    return temp;
}

Fraction Fraction::operator -- ()
{
    //pre:obtains a a fraction by reference
    //post: subtracts fraction by one.
    num-=den;
    simplify();
    return *this;
}
Fraction Fraction::operator -- (int)
{
    //pre:obtains a a fraction by reference
    //post: subtracts fraction by one.
    Fraction temp(num,den);
    num-=den;
    simplify();
    return temp;
}
//bool overloaded operations
bool operator > (const Fraction leftOp, const Fraction rightOp)
{
   return leftOp.num * rightOp.den > leftOp.den * rightOp.num;
}
bool operator >= (const Fraction leftOp, const Fraction rightOp)
{
   return leftOp.num * rightOp.den >= leftOp.den * rightOp.num;
}
bool operator < (const Fraction leftOp, const Fraction rightOp)
{
   return leftOp.num * rightOp.den < leftOp.den * rightOp.num;
}
bool operator <= (const Fraction leftOp, const Fraction rightOp)
{
   return leftOp.num * rightOp.den <= leftOp.den * rightOp.num;
}
bool operator == (const Fraction leftOp, const Fraction rightOp)
{
   return leftOp.num * rightOp.den == leftOp.den * rightOp.num;
}
bool operator != (const Fraction leftOp, const Fraction rightOp)
{
   return leftOp.num * rightOp.den != leftOp.den * rightOp.num;
}
//pre: obtains two fraction variables
//post:returns true for false depending on if the bool statement is true or false.


}
