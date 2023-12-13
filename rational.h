/**
 * Title: Lab 5: rational.h
 * Author: Chris Kendall
 * Date: 1 June 2023
 */

#ifndef RATIONAL_OPERATOR_OVERLOAD_ASSIGNMENT_RATIONAL_H
#define RATIONAL_OPERATOR_OVERLOAD_ASSIGNMENT_RATIONAL_H

#include <iostream>

using std::string;
using std::ostream;


class Rational {
    int _numerator, _denominator;
public:
    // Constructors
    Rational(int numerator, int denominator);
    Rational(double number);

    // Overload the following operators
    const Rational operator+(const Rational& rhs)const;
    const Rational operator-(const Rational& rhs)const;
    const Rational operator/(const Rational& rhs)const;
    const Rational operator*(const Rational& rhs)const;
    const Rational operator-()const;

    const Rational operator+=(const Rational& rhs);
    const Rational operator-=(const Rational& rhs);
    const Rational operator*=(const Rational& rhs);
    const Rational operator/=(const Rational& rhs);
    const Rational operator=(const Rational& rhs);

    bool operator==(const Rational& rhs)const;
    bool operator!=(const Rational& rhs)const;
    bool operator>(const Rational& rhs)const;
    bool operator>=(const Rational& rhs)const;
    bool operator<=(const Rational& rhs)const;
    bool operator<(const Rational& rhs)const;

    friend ostream& operator<<(ostream& os, const Rational& rhs);

    const string ToString();
    const double ToDouble() const;

    const int FindGCD(int numerator, int denominator) const;
     /*
     >>>>>> REMEMBER THE NUMBER IS ALWAYS SIMPLIFIED <<<<<<<

     */

};

#endif //RATIONAL_OPERATOR_OVERLOAD_ASSIGNMENT_RATIONAL_H
