/*
    The Fraction class can be used to represent numbers that can be expressed as
    the ratio of two integers, that is, rational numbers or "Fraction"s.  All of
    the  expected operators are provided, including stream extraction, stream
    insertion, relational operators, and arithmetic operators.
// Listing of all class member function prototpyes with pre and post condition comments
// Note with 22 function prototypes this multiline comment section will be quite large
*/
//xander maniaci, cs10b
#ifndef FRACTION_H
#define FRACTION_H



namespace cs10b_fraction {
//class declaration
    class Fraction
{
    //member functions
    public:
        //default constructor
        Fraction(int n = 0, int d = 1)
        {
            if(n%d == 0)
            {
                num = n/d;
                den = 1;
            }else{
            num = n;
            den = d;
            }
            assert(den != 0);
            simplify();
        };//overloaded o stream and istream member functions
        friend std::ostream& operator << (std::ostream &out, const Fraction printMe);
        //pre:obtains a fraction
        //post: prints fraction on screen in proper form.
        friend std::istream& operator >> (std::istream &in, Fraction readMe);
        //couldn't get to work. hope you go over this in class at a later date.

        //overloaded operations for addition subtraction multiplication and division
        friend Fraction operator + (const Fraction leftOp, const Fraction rightOp);
        Fraction operator += (const Fraction rightOp);
        //pre:obtains a two fractions
        //post: adds fractions and returns result
        //pre: obtains two fraction variables
        //post:returns true for false depending on if the bool statement is true or false.
        friend Fraction operator - (const Fraction leftOp, const Fraction rightOp);
        Fraction operator -= (const Fraction rightOp);
        //pre:obtains a two fractions
        //post: subtracts fractions and returns result

        friend Fraction operator * (const Fraction leftOp, const Fraction rightOp);
        Fraction operator *= (const Fraction rightOp);
        //pre:obtains a two fractions
        //post: multiplies fractions and returns result

        friend Fraction operator / (const Fraction leftOp, const Fraction rightOp);
        Fraction operator /= (const Fraction rightOp);
        //pre:obtains a two fractions
        //post: divides fractions and returns result

        //increment operators
        Fraction operator ++ ();
        Fraction operator ++ (int);
        //pre:obtains a a fraction by reference
        //post: increment fraction by one in pre or post.
        Fraction operator -- ();
        Fraction operator -- (int);
        //pre:obtains a a fraction by reference
        //post: subtracts fraction by one.

        //bool overloaded operations
        friend bool operator > (const Fraction leftOp, const Fraction rightOp);
        friend bool operator >= (const Fraction leftOp, const Fraction rightOp);
        friend bool operator < (const Fraction leftOp, const Fraction rightOp);
        friend bool operator <= (const Fraction leftOp, const Fraction rightOp);
        friend bool operator == (const Fraction leftOp, const Fraction rightOp);
        friend bool operator != (const Fraction leftOp, const Fraction rightOp);
        //pre: obtains two fraction variables
        //post:returns true for false depending on if the bool statement is true or false.


    private:
        int num, den;
        //function for simplifying fractions
        void simplify();
        //pre: obtains a fraction
        //post. simplifies fraction and returns it
};
}
#endif
/*
Project#2: Fraction class (ADT) client program to test CLASS INVARIANT
There are two data members used to represent the denominator and numerator
for each instance of a Fraction class object class.
The client code provides an interface to test correct operations on fraction
objects that are negative, improper (larger numerator than denominator),
or whole numbers (denominator of 1).
Here is a list test type and order in which the tests will be conducted
1. BasicTest
2. RelationTest
3. BinaryMathTest
4. MathAssignTest

***********************************************************************
* Basic Test: Testing member constructor, simplify() and nonmember    *
* friend ostream << operator for basic Fraction object creation &     *
* printing(Fractions should be in reduced form, and as mixed numbers.)*
***********************************************************************
Fraction [0] = 1/2
Fraction [1] = -5/7
Fraction [2] = 10
Fraction [3] = -4
Fraction [4] = 0
Fraction [5] = 4+2/3
Fraction [6] = 0

***********************************************************************
* Basic Test: Testing simplify() and nonmember friend istream >> and  *
* ostream << operators for reading and display of Fraction objects    *
* from data file                                                      *
***********************************************************************
Enter file name with fraction data to read: frac_data.txt
Read Fraction = 0
Read Fraction = 0
Read Fraction = 0
Read Fraction = 0
Read Fraction = 0
Read Fraction = 0
Read Fraction = 0
Read Fraction = 0
Read Fraction = 0
Read Fraction = 0
Read Fraction = 0
Read Fraction = 0
Read Fraction = 0
Read Fraction = 0
Read Fraction = 0
Read Fraction = 0
Read Fraction = 0

***********************************************************************
* RelationTest: Testing nonmember friend binary Boolean <, <=, >, >=, *
*  ==, != relational operators between Fractions                      *
***********************************************************************
Comparing 1/2 to -1/2
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true
Comparing -1/2 to 1/2
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing 1/2 to 1/10
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true
Comparing 1/10 to 0
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true
Comparing 0 to 0
        Is left < right? false
        Is left <= right? true
        Is left > right? false
        Is left >= right? true
        Does left == right? true
        Does left != right ? false

***********************************************************************
* RelationTest: Testing nonmember friend binary Boolean <, <=, >, >=, *
* ==, != relations between Fractions and integers                     *
***********************************************************************
Comparing -1/2 to 2
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing -3 to 1/4
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true

***********************************************************************
* BinaryMathTest: Testing nonmember friend binary arithmetic +, -, *, *
* / operators between Fractions                                       *
***********************************************************************
1/6 + 1/3 = 1/2
1/6 - 1/3 = -1/6
1/6 * 1/3 = 1/18
1/6 / 1/3 = 1/2
1/3 + -2/3 = -1/3
1/3 - -2/3 = 1
1/3 * -2/3 = -2/9
1/3 / -2/3 = -1/2
-2/3 + 5 = 4+1/3
-2/3 - 5 = -5+2/3
-2/3 * 5 = -3+1/3
-2/3 / 5 = -2/15
5 + -1+1/3 = 3+2/3
5 - -1+1/3 = 6+1/3
5 * -1+1/3 = -6+2/3
5 / -1+1/3 = -3+3/4

***********************************************************************
* BinaryMathTest: Testing nonmember friend binary arithmetic +, -, *, *
* / operators between Fractions and integers                          *
***********************************************************************
-1/2 + 4 = 3+1/2
-1/2 - 4 = -4+1/2
-1/2 * 4 = -2
-1/2 / 4 = -1/8
3 + -1/2 = 2+1/2
3 - -1/2 = 3+1/2
3 * -1/2 = -1+1/2
3 / -1/2 = -6

***********************************************************************
* MathAssignTest: Testing member shorthand arithmetic assignment +=,  *
* -=, *=, /= operators on Fractions                                   *
***********************************************************************
1/6 += 4 = 4+1/6
1/6 -= 4 = -3+5/6
1/6 *= 4 = 2/3
1/6 /= 4 = 1/24
4 += -1/2 = 3+1/2
4 -= -1/2 = 4+1/2
4 *= -1/2 = -2
4 /= -1/2 = -8
-1/2 += 5 = 4+1/2
-1/2 -= 5 = -5+1/2
-1/2 *= 5 = -2+1/2
-1/2 /= 5 = -1/10

***********************************************************************
* MathAssignTest: Testing member shorthand arithmetic assignment +=,  *
* -=, *=, /= operators using integers                                 *
***********************************************************************
-1/3 += 3 = 2+2/3
-1/3 -= 3 = -3+1/3
-1/3 *= 3 = -1
-1/3 /= 3 = -1/9

***********************************************************************
* MathAssignTest: Testing member increment/decrement prefix and       *
* postfix operators                                                   *
***********************************************************************
Now g = -1/3
g++ = -1/3
Now g = 2/3
++g = 1+2/3
Now g = 1+2/3
g-- = 1+2/3
Now g = 2/3
--g = -1/3
Now g = -1/3

Project#2 -Fraction class (ADT) testing now concluded.
Check output for correct results from the Fraction class (ADT) implementation.

Process returned 0 (0x0)   execution time : 5.421 s
Press any key to continue.*/
