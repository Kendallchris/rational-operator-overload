/**
 * Title: Lab 5: rational.cpp
 * Author: Chris Kendall
 * Date: 1 June 2023
 */

#include "rational.h"

#include <sstream>
#include <cmath>

using std::stringstream;
using std::cout;
using std::endl;
using std::invalid_argument;

/**
 * Constructor for Rational. If denominator is '0' throws invalid argument. Uses the Euclidean algorithm to find the gcd
 * between the numerator and denominator. Then uses that to simplify the terms before storing them in the Rational object.
 * @param numerator the int numerator
 * @param denominator the int denominator
 */
Rational::Rational(int numerator, int denominator) {
    if (denominator == 0) {
        throw invalid_argument("Cannot have '0' in the denominator");
    }

    int gcd = FindGCD(numerator, denominator);

    _numerator = round(numerator / gcd);
    _denominator = round(denominator / gcd);
}

/**
 * Constructor for Rational. Takes a double parameter and attempts to match it with an integer numerator and denominator
 * by separating the decimal portion from the whole number portion then multiplying the 'numerator' value (starts at 1)
 * by 10 and the decimal portion by 10 until the decimal portion is a whole number. It then uses the gcd between the newly
 * multiplied decimal portion added to the whole number portion of the 'number' parameter (multiplied by the denominator to
 * combine the terms) and the denominator. It then stores the calculated numerator and denominator in the Rational object.
 * @param number double rational number to find an int numerator and denominator for
 */
Rational::Rational(double number) {
    int whlNum = static_cast<int>(number);
    double decimal = number - whlNum;
    int denominator = 1;
    while (decimal - static_cast<int>(decimal) != 0) {
        decimal *= 10.0;
        denominator *= 10;
    }
    int numerator = whlNum * denominator + static_cast<int>(decimal);
    int gcd = FindGCD(numerator, denominator);
    _numerator = round(numerator / gcd);
    _denominator = round(denominator / gcd);
}

/**
 * Overloads the '+' operator.
 * @param rhs the Rational object right hand side of the argument
 * @return the evaluation of the two rational numbers added together as a Rational object.
 */
const Rational Rational::operator+(const Rational &rhs) const {
    int num;
    int den;
    if (this->_denominator == rhs._denominator) {
        num = this->_numerator + rhs._numerator;
        den = this->_denominator;
    } else {
        num = (this->_numerator * rhs._denominator) + (rhs._numerator * this->_denominator);
        den = this->_denominator * rhs._denominator;
    }

    return Rational(num, den);
}

/**
 * Overloads the '-' operator.
 * @param rhs the Rational object right hand side of the argument
 * @return the evaluation of the two rational numbers subtracted from each other as a Rational object.
 */
const Rational Rational::operator-(const Rational &rhs) const {
    return *this + -rhs;
}

/**
 * Overloads the '/' operator.
 * @param rhs the Rational object right hand side of the argument
 * @return the evaluation of the two rational numbers divided as a Rational object.
 */
const Rational Rational::operator/(const Rational &rhs) const {
    int num = this->_numerator * rhs._denominator;
    int den = this->_denominator * rhs._numerator;

    return Rational(num, den);
}

/**
 * Overloads the '*' operator.
 * @param rhs the Rational object right hand side of the argument
 * @return the evaluation of the two rational numbers multiplied together as a Rational object.
 */
const Rational Rational::operator*(const Rational &rhs) const {
    int num = this->_numerator * rhs._numerator;
    int den = this->_denominator * rhs._denominator;

    return Rational(num, den);
}

/**
 * Unary overloads the '-' operator.
 * @return a new Rational object representing the implied lhs Rational object multiplied by -1.
 */
const Rational Rational::operator-() const {
    return Rational(-this->_numerator, this->_denominator);
}

/**
 * Overloads the '+=' operator.
 * @param rhs the Rational object right hand side of the argument
 * @return
 */
const Rational Rational::operator+=(const Rational &rhs) {
    *this = *this + rhs;
    return *this;
}

/**
 * Overloads the '-=' operator.
 * @param rhs the Rational object right hand side of the argument
 * @return the lhs Rational minus rhs.
 */
const Rational Rational::operator-=(const Rational &rhs) {
    *this = *this - rhs;
    return *this;
}

/**
 * Overloads the '*=' operator.
 * @param rhs the Rational object right hand side of the argument
 * @return the lhs Rational multiplied by rhs.
 */
const Rational Rational::operator*=(const Rational &rhs) {
    *this = *this * rhs;
    return *this;
}

/**
 * Overloads the '/=' operator.
 * @param rhs the Rational object right hand side of the argument
 * @return the lhs Rational divided by rhs.
 */
const Rational Rational::operator/=(const Rational &rhs) {
    *this = *this / rhs;
    return *this;
}

/**
 * Overloads the '=' operator.
 * @param rhs the Rational object right hand side of the argument
 * @return the lhs Rational, set to the rhs Rational's value.
 */
const Rational Rational::operator=(const Rational &rhs) {
    this->_numerator = rhs._numerator;
    this->_denominator = rhs._denominator;
    return *this;
}

/**
 * Overloads the '==' operator.
 * @param rhs the Rational object right hand side of the argument
 * @return true if lhs == rhs. False otherwise.
 */
bool Rational::operator==(const Rational &rhs) const {
    if (this->_numerator == rhs._numerator) {
        if (this->_denominator == rhs._denominator) {
            return true;
        }
    }
    return false;
}

/**
 * Overloads the '!=' operator.
 * @param rhs the Rational object right hand side of the argument
 * @return true if lhs != rhs. False if they are =.
 */
bool Rational::operator!=(const Rational &rhs) const {
    if (*this == rhs) {
        return false;
    }
    return true;
}

/**
 * Overloads the '>' operator.
 * @param rhs the Rational object right hand side of the argument
 * @return true if the lhs is > rhs. False otherwise.
 */
bool Rational::operator>(const Rational &rhs) const {
    double dlhs = this->ToDouble();
    double drhs = rhs.ToDouble();
    if (dlhs > drhs) {
        return true;
    }
    return false;
}

/**
 * Overloads the '>=' operator.
 * @param rhs the Rational object right hand side of the argument
 * @return true if the lhs is >= rhs. False otherwise.
 */
bool Rational::operator>=(const Rational &rhs) const {
    double dlhs = this->ToDouble();
    double drhs = rhs.ToDouble();
    if (dlhs >= drhs) {
        return true;
    }
    return false;
}

/**
 * Overloads the '<=' operator.
 * @param rhs the Rational object right hand side of the argument
 * @return true if the lhs is <= rhs. False otherwise.
 */
bool Rational::operator<=(const Rational &rhs) const {
    double dlhs = this->ToDouble();
    double drhs = rhs.ToDouble();
    if (dlhs <= drhs) {
        return true;
    }
    return false;
}

/**
 * Overloads the '<' operator.
 * @param rhs the Rational object right hand side of the argument
 * @return true if the lhs is < rhs. False otherwise.
 */
bool Rational::operator<(const Rational &rhs) const {
    double dlhs = this->ToDouble();
    double drhs = rhs.ToDouble();
    if (dlhs < drhs) {
        return true;
    }
    return false;
}

/**
 * Converts the Rational object to a string. If the denominator is '1' it just returns the numerator.
 * @return a string representation of the Rational object
 */
const string Rational::ToString() {
    stringstream rep;

    // if denominator is '1' then just print the numerator
    if (this->_denominator == 1) {
        rep << this->_numerator << "";
        return rep.str();
    }

    rep << this->_numerator << "/" << this->_denominator;
    return rep.str();
}

/**
 * Returns a double representation of the Rational object.
 * @return a double representation of the Rational object
 */
const double Rational::ToDouble() const {
    double eval = double(this->_numerator) / this->_denominator;
    return eval;
}

/**
 * Overloads the '<<' operator, allowing similar function for printing the Rational object as a string as using cout
 * on a string.
 * @param os desired ostream to be output to (implied by the lhs of the '<<')
 * @param rhs the Rational object to be output (implied by the rhs of the '<<'_
 * @return the Rational object represented as a string.
 */
ostream &operator<<(ostream &os, const Rational &rhs) {
    stringstream rep;

    // if denominator is '1' then just print the numerator
    if (rhs._denominator == 1) {
        os << rhs._numerator << "";
        return os;
    }

    os << rhs._numerator << "/" << rhs._denominator;
    return os;
}

/**
 * This is a helper method for the constructors. Find the greatest common divisor between the two passed ints. If (the denominator / the numerator)
 * minus (the denominator / the numerator) rounded - ie. without the decimal part - is between .000001 and .000000001 I assume that the division is
 * "close enough" to handle cases where, like in our test code, '.111111' is passed to the double constructor which calls FindGCD(111111,1000000).
 * @param numerator integer numerator
 * @param denominator integer denominator
 * @return the gcd between the two parameters.
 */
const int Rational::FindGCD(int numerator, int denominator) const{
    int a = abs(numerator);
    int b = abs(denominator);

    if (((static_cast<double>(denominator) / static_cast<double>(numerator)) - round((static_cast<double>(denominator) / static_cast<double>(numerator))) < .000001) && ((static_cast<double>(denominator) / static_cast<double>(numerator)) - round((static_cast<double>(denominator) / static_cast<double>(numerator))) > .000000001)) {
        return numerator;
    }

    // Euclidean algorithm
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    // end Euclidean algorithm

    int gcd = a;

    return gcd;
}
