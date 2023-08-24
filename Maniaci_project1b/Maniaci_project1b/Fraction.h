
//Xander Maniaci, cs10b, 4/9/20, Sujan Sarker, Fraction.h
//fraction class creates a fraction data type.member functions are use for math equations mostly when comparing two fractions.
#ifndef Fraction_H// need this for using default constructor
#define Fraction_H// need this for using default constructor
class Fraction
{
public://interface to access private data members
    Fraction();
    //pre: a fraction data type is created but not defined
    //post:default constructor for the fraction data type

    Fraction(int,int);
    //pre: a fraction data type is created and defined. obtains two ints.
    //post:creates a fraction data type using two ints.

    bool isGreaterThan (Fraction/*in*/) const;
    //pre:obtains two fraction variables one is passed by reference
    //post: test to see if one fraction is greater than another returns true if the reference variable is greater. false if not.

    bool isEqualTo(Fraction/*in*/)const;//an observer/getter
    //pre: obtains two fraction data types one is passed by reference
    //post:compares both fractions to see if they are equal to each other.

    void getFraction();
    //pre: gets a fraction variable from main passed by reference
    //post:inputs values from user into the fraction variable

    Fraction AddedTo(Fraction/*inout*/)const;//an observer/getter
    //pre: obtains two fraction data types one is passed by reference
    //post: adds two fractions together and returns the result

    Fraction Subtract(Fraction/*inout*/)const;//an observer/getter
    //pre: obtains two fraction data types one is passed by reference
    //post: subtracts two fractions together and returns the result

    Fraction MultipliedBy(Fraction/*inout*/)const;//an observer/getter
    //pre: obtains two fraction data types one is passed by reference
    //post: multiplys two fractions together and returns the result

    Fraction DividedBy(Fraction/*inout*/)const;//an observer/getter
    //pre: obtains two fraction data types one is passed by reference
    //post: divides two fractions together and returns the result

    void showFraction() const;
    //pre: obtains a fraction data type passed by reference
    //post: displays the fraction data type.

private:
    void simplify();
    int numorator;
    int denominator;
};
#endif // Fraction_H need this for using default constructor

