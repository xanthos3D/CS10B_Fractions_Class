//xander maniaci
#include <iostream>
#include "fraction.h"
#include <cassert>
using namespace std;
//fraction class creates a fraction data type.member functions are use for math equations mostly when comparing two fractions.
//void class function to print fractions.
void Fraction::simplify()
{
    //pre: is called by a public member function and sent a fraction data type by reference.
    //post: simplifys the fraction variable sent to it.
    for(int counter = 2;counter<9999;counter++)
    {
        while(numorator%counter == 0 && denominator%counter == 0)
        {
            numorator /= counter;
            denominator /= counter;
        }
    }
    if(numorator == denominator)
    {
        numorator = 1;
        denominator = 1;
    }
}

Fraction::Fraction()
{
    //pre: a fraction data type is created but not defined
    //post:default constructor for the fraction data type
  numorator = 0;
  denominator = 1;
}
Fraction::Fraction(int numor,int denom)
{
    //pre: a fraction data type is created and defined. obtains two ints.
    //post:creates a fraction data type using two ints.
    Fraction result;
    result.numorator = numor;
    assert(denom != 0);
    result.denominator = denom;
    result.simplify();
    numorator = result.numorator;
    denominator = result.denominator;

}
void Fraction::getFraction()
{
    //pre: gets a fraction variable from main passed by reference
    //post:inputs values from user into the fraction variable
    cout<<"Enter values for a fraction object"<<endl;
    cout<<"numorator: ";
    cin>>numorator;
    cout<<"Denominator: ";
    cin>>denominator;

}

void Fraction::showFraction() const
{
    //pre:is called
    //post: prints out fraction data type in proper format.
    cout<<numorator<<"/"<<denominator;
}
//value returning class function for multiplying fraction data types
Fraction Fraction::MultipliedBy(Fraction  value2) const
{
    //pre:obtains two fraction variables one is passed by reference
    //post: returns the result of multiplication
    Fraction  result;//temporary object to help with the binary operation
    result.numorator = numorator * value2.numorator;
    result.denominator = denominator * value2.denominator;
    result.simplify();
    return result;
}
//value returning class function for dividing fraction data types
Fraction Fraction::DividedBy(Fraction  value2) const
{
    //pre:obtains two fraction variables one is passed by reference
    //post: returns the result of division
    Fraction  result;//temporary object to help with the binary operation
    result.numorator = numorator * value2.denominator;
    result.denominator = denominator * value2.numorator;
    result.simplify();
    return result;
}
//value returning class function for subtracting fraction data types
Fraction Fraction::Subtract(Fraction  value2) const
{
    //pre:obtains two fraction variables one is passed by reference
    //post: returns the result of subtraction
    Fraction  result;//temporary object to help with the binary operation
    if(denominator == value2.denominator)
    {
    result.denominator = denominator;
    result.numorator = numorator - value2.numorator;
    }else{
    result.numorator = (numorator * value2.denominator) - (value2.numorator * denominator);
    result.denominator = denominator * value2.denominator;
    }
    result.simplify();
    return result;
}
//value returning class function for adding fraction data types
Fraction Fraction::AddedTo(Fraction  value2) const
{
    //pre:obtains two fraction variables one is passed by reference
    //post: returns the result of addition
    Fraction  result;//temporary object to help with the binary operation
    if(denominator == value2.denominator)//if statement to test if the bases of the denominator are the same.
    {
    result.denominator = denominator;
    result.numorator = numorator + value2.numorator;
    }else{
    result.numorator = (numorator * value2.denominator) + (value2.numorator * denominator);
    result.denominator = denominator * value2.denominator;
    }
    result.simplify();
    return result;
}
//value returning class function to see if fractions are equal to each other
bool Fraction::isEqualTo(Fraction  value2) const
{
    //pre:obtains two fraction variables one is passed by reference
    //post: returns bool value depending on if the fractions are equal or not.
    bool test = false;//temporary bool value
    if(numorator == value2.numorator && denominator == value2.denominator)
    {
        test = true;
    }
    return test;
}
bool Fraction::isGreaterThan(Fraction value2/*in*/) const
{
    //pre:obtains two fraction variables one is passed by reference
    //post: test to see if one fraction is greater than another returns true if the reference variable is greater. false if not.
    if(denominator == value2.denominator)//if statement to test if the bases of the denominator are the same.
    {
        if(numorator > value2.numorator)
        {
            return true;
        }else if(numorator < value2.numorator)
        {
            return false;
        }else
        {
            return false;
        }

    }else if(numorator *value2.denominator > value2.numorator * denominator)
    {
      return true;
    }else if(numorator *value2.denominator < value2.numorator * denominator)
    {
        return false;
    }else
    {
        return false;
    }
}

