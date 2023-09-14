/**
 * FERRER, Matt Brycen L.
 * ENGG 31 - J
 * Project 1 - Fraction Calculator
 * Fraction.h
*/

#ifndef FRACTION_CLASS
#define FRACTION_CLASS

#include <iostream>

class Fraction
{
  private:
    int numerator;
    int denominator;

  public:
    Fraction();
    Fraction(int x, int y);
    Fraction toLowestTerms();
    Fraction operator=(const Fraction& f) const;
    Fraction operator+(const Fraction& f) const;
    Fraction operator-(const Fraction& f) const;
    Fraction operator*(const Fraction& f) const;
    Fraction operator/(const Fraction& f) const;
    friend std::ostream& operator<<(std::ostream& output,
    const Fraction& f);
    friend std::istream& operator>>(std::istream& input, 
    Fraction& f);
};

#endif // FRACTION_CLASS
