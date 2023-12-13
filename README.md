[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/UpyUBvKy)
# A Class to Represent Rational Numbers with Operators Overload

## Overload the Arithmetic Operators for Rational Numbers

Overload the following operators:

* `-Rational`
* `Rational + Rational`
* `Rational - Rational`
* `Rational * Rational`
* `Rational / Rational`
* `Rational += Rational`
* `Rational -= Rational`
* `Rational *= Rational`
* `Rational /= Rational`
* `Rational = Rational`
* `Rational == Rational`
* `Rational != Rational`
* `Rational > Rational`
* `Rational >= Rational`
* `Rational <= Rational`
* `Rational < Rational`

The class will have the following data members:
```c++
int _numerator, _denominator;
```
And the following constructors:
```c++
Rational(int numerator, int denominator);
Rational(double number); // If you don't implement it set _numerator to 0 and _denominator to 1
```



## Extra Credit
* Implementing the stream insertion operator overload
* Implementing the constructor that receives a double and convert that double to rational

## Rules...
The same as every other lab.