/**
 * FERRER, Matt Brycen L.
 * ENGG 31 - J
 * Project 1 - Fraction Calculator
 * Fraction.cpp
*/

#include "Fraction.h"
#include <algorithm>
#include <iostream>
#include <numeric> 
#include <sstream>
#include <string>

using namespace std;

// initialize new fraction to 0/1 if not specified
Fraction::Fraction()
{
  numerator = 0;
  denominator = 1;
}

// initialize a fraction with specified numerator and denominator
Fraction::Fraction(int x, int y)
{
  numerator = x;
  denominator = y;
}

// reduces a fraction to lowest terms
Fraction Fraction::toLowestTerms()
{
  if (denominator != 0)  // check if fraction is defined
  {
    int x = numerator;  // temporary variables x, y
    int y = denominator;
    numerator /= gcd(x, y);
    denominator /= gcd(x, y);
  }
  return Fraction(numerator, denominator);
}

// overload the assignment = operator
Fraction Fraction::operator=(const Fraction& f) const
{
  Fraction output;
  output.numerator = f.numerator;
  output.denominator = f.denominator;
  return output;
}

// overload the addition + operator
Fraction Fraction::operator+(const Fraction& f) const
{
  Fraction output;
  output.numerator = numerator * f.denominator + 
    f.numerator * denominator;
  output.denominator = denominator * f.denominator;
  return output.toLowestTerms();
}

// overload the subtraction - operator
Fraction Fraction::operator-(const Fraction& f) const
{
  Fraction output;
  output.numerator = numerator * f.denominator -
    f.numerator * denominator;
  output.denominator = denominator * f.denominator;
  return output.toLowestTerms();
}

// overload the multiplication * operator
Fraction Fraction::operator*(const Fraction& f) const
{
  Fraction output;
  output.numerator = numerator * f.numerator;
  output.denominator = denominator * f.denominator;
  return output.toLowestTerms();
}

// overload the division / operator
Fraction Fraction::operator/(const Fraction& f) const
{
  // check if divisor is not 0
  if (f.numerator != 0)
  {
    Fraction output;
    output.numerator = numerator * f.denominator;
    output.denominator = denominator * f.numerator;
    return output.toLowestTerms();
  }
  else return Fraction(0, 0);  // undefined if divisor = 0
}

// overload the insertion << operator
ostream& operator<<(ostream& output, const Fraction& f)
{
  // format as undefined if denominator is 0
  if (f.denominator == 0)
  {
    output << "undefined";
  }

  else // valid fraction
  {
    // format as (a) if integer
    if (f.numerator % f.denominator == 0)
    {
      output << f.numerator / f.denominator;
    }

    // format as (a/b) if not integer
    else
    {
      output << f.numerator << "/" << f.denominator;
    }
  }

  return output;
}

// overload the extraction >> operator
istream& operator>>(istream& input, Fraction& f)
{
  // process string input by the user into numerator and denominator
  Fraction original = f;
  stringstream ss;
  string input_str, numerator_str, denominator_str, test_str;
  int numerator;
  int denominator;

  // take cin input into string
  getline(input, input_str);  

  // convert to all lowercase
  for (int i = 0; i < input_str.length(); i++)
  {
    input_str[i] = tolower(input_str[i]);
  }

  // remove input spaces
  input_str.erase(remove(input_str.begin(), input_str.end(), ' '), 
    input_str.end());

  // remove = sign
  int equals_place = input_str.find('=');
  if (equals_place != string::npos)
  {
    input_str.erase(equals_place, equals_place + 1);
  }

  // split into numerator string and denominator string
  ss << input_str;
  getline(ss, numerator_str, '/');
  getline(ss, denominator_str);
  
  try
  {
    numerator = stoi(numerator_str);  // convert string to int

    // if fraction in form (a/b)
    if (denominator_str.length() > 0)
    {
      denominator = stoi(denominator_str);
    }

    // if integer in form (a)
    else 
    {
      denominator = 1;
    }

    f.numerator = numerator;
    f.denominator = denominator;
    f = f.toLowestTerms();
  }

  catch (...)  // if parsing fraction failed
  {
    cout << "Invalid fraction entered.\n";
    f = original.toLowestTerms();  // do not change fraction
  }

  return input;
}
