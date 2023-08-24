#include <iostream>
using namespace std;

class Fraction
{
public://interface to access private data members
    void  set(int/*in*/, int/*in*/);//transformer
    bool isEqualTo(Fraction/*in*/);//an observer/getter
    Fraction addedTo(Fraction/*inout*/);//an observer/getter
    Fraction subtract(Fraction/*inout*/);//an observer/getter
    Fraction multipliedBy(Fraction/*inout*/);//an observer/getter
    Fraction dividedBy(Fraction/*inout*/);//an observer/getter
    void print();
private:
    int numorator;
    int denominator;
};

int main()
{
    //creates class data type variables
    Fraction f1;
    Fraction f2;
    Fraction result;

    f1.set(9, 8);//calls getter function to set fractions
    f2.set(2, 3);

    cout<<"\nArithmetic operations with fraction objects stored in the results class object\n";
    cout<<"------------------------------------------------------------------------------\n\n";
    //calls member functions of class for texting.
    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)){
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }

    cout<<"\n---------------------------------------------------------\n";
    cout<<"\nFraction class implementation test now successfully concluded\n";
    // system ("PAUSE");
    return 0;
}

//********************************************************
//class function definitions
//void class function to set fraction variables.
void  Fraction::set(int numor/*in*/, int denom/*in*/)
{
    //pre:gets two values from main
    //post: sets variables to the fraction data type
  numorator = numor;
  denominator = denom;
}
//void class function to print fractions.
void Fraction::print()
{
    //pre:is called
    //post: prints out fraction data type in proper format.
    cout<<numorator<<"/"<<denominator;
}
//value returning class function for multiplying fraction data types
Fraction Fraction::multipliedBy(Fraction  value2)
{
    //pre:obtains two fraction variables one is passed by reference
    //post: returns the result of multiplication
    Fraction  result;//temporary object to help with the binary operation
    result.numorator = numorator * value2.numorator;
    result.denominator = denominator * value2.denominator;
    return result;
}
//value returning class function for dividing fraction data types
Fraction Fraction::dividedBy(Fraction  value2)
{
    //pre:obtains two fraction variables one is passed by reference
    //post: returns the result of division
    Fraction  result;//temporary object to help with the binary operation
    result.numorator = numorator * value2.denominator;
    result.denominator = denominator * value2.numorator;
    return result;
}
//value returning class function for subtracting fraction data types
Fraction Fraction::subtract(Fraction  value2)
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
    return result;
}
//value returning class function for adding fraction data types
Fraction Fraction::addedTo(Fraction  value2)
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
    return result;
}
//value returning class function to see if fractions are equal to each other
bool Fraction::isEqualTo(Fraction  value2)
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

