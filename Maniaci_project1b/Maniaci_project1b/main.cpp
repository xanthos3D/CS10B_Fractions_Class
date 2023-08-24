/*Client.cpp is set-up as a Fraction class implementation and test driver program - DO NOT CHANGE SOURCE CODE
All necessary class objects are declared and defined here to test various class related operations.
HINT: see comments for specific class related function calls*/

#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
Fraction f1(9,8); //calling a parameterized class constructor
Fraction f2(2,3);
Fraction result; //calling a default class constructor
const Fraction f3(12, 8);
const Fraction f4(202, 303);
Fraction f5,f6;

cout<<"C++ CLASS MULTI-FILE PROJECT"<<endl;
cout<<"Client.cpp - testing a Fraction class implementation\n";
cout<<"----------------------------------------------------\n\n";

cout << "The result object starts off at ";
result.showFraction(); //calling a void "observer" function
cout << endl;


cout<<"\nArithmetic operations with Fraction objects stored in the results class object\n";
cout<<"------------------------------------------------------------------------------\n\n";

cout << "The sum of ";
f1.showFraction();
cout << " and ";
f2.showFraction();
cout << " is ";
result = f1.AddedTo(f2); //a class binary operation - a value-returning "observer" function
result.showFraction();
cout << endl;

cout << "The difference of ";
f1.showFraction();
cout << " and ";
f2.showFraction();
cout << " is ";
result = f1.Subtract(f2); //a class binary operation - a value-returning "observer" function
result.showFraction();
cout << endl;

cout << "The product of ";
f1.showFraction();
cout << " and ";
f2.showFraction();
cout << " is ";
result = f1.MultipliedBy(f2); //a class binary operation - a value-returning "observer" function
result.showFraction();
cout << endl;

result = f3.DividedBy(f4); //a class binary operation - a value-returning "observer" function
cout << "The quotient of ";
f3.showFraction();
cout << " and ";
f4.showFraction();
cout << " is ";
result.showFraction();
cout << endl;

cout<<"\nInput and Output operations for two new class objects\n";
cout<<"-----------------------------------------------------\n\n";

f5.getFraction(); //a class input operation - a transformer or setter function
f5.showFraction(); //a class output operation - an observer or getter function
cout<<endl<<endl;
f6.getFraction();
f6.showFraction();
cout<<endl<<endl;

cout<<"\nA Boolean operation comparing two class objects\n";
cout<<"------------------------------------\n\n";

if (f5.isGreaterThan(f6)){ //a class relational expression - boolean operation/function
f5.showFraction();
cout <<" is greater than ";
f6.showFraction();
cout<<endl;
} else {
f5.showFraction();
cout <<" is less than ";
f6.showFraction();
cout<<endl;
}

cout<<"\n---------------------------------------------------------\n";
cout<<"\nFraction class implementation test now successfully concluded\n";

// system ("PAUSE");

return 0;
}


