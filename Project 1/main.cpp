/**
 * FERRER, Matt Brycen L.
 * ENGG 31 - J
 * Project 1 - Fraction Calculator
 * main.cpp
*/

#include "Fraction.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  Fraction a, b;
  string input;
  char selectedFraction;

  // print introduction
  cout << "Project 1 - Fraction Calculator\n";
  cout << "Enter 'x' to exit the program.\n";

  while (true)
  {
    // output
    cout << "a = " << a << "\t";
    cout << "b = " << b << "\n";
    cout << "a+b = " << (a+b).toLowestTerms() << "\t\t";
    cout << "a-b = " << (a-b).toLowestTerms() << "\t\t";
    cout << "a*b = " << (a*b).toLowestTerms() << "\t\t";
    cout << "a/b = " << (a/b).toLowestTerms() << "\n\n";
    cin >> selectedFraction;  // take letter input from user
    
    // update fraction specified
    if (selectedFraction == 'a')
    {
      cin >> a;
    }
    else if (selectedFraction == 'b')
    {
      cin >> b;
    }
    else if (selectedFraction == 'x')
    {
      cout << "Exited program.\n";
      break;
    }
    else
    {
      cout << "Invalid input.\n";
    }
  }

  return 0;
}
