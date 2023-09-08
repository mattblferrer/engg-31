/**
 * FERRER, Matt Brycen L.
 * ENGG 31 - J
 * Project 1 - Fraction Calculator
 * main.cpp
*/

#include "Fraction.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  Fraction a;
  Fraction b;
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
    getline(cin, input);  // take fraction input from user

    // convert to all lowercase
    for (int i = 0; i < input.length(); i++)
    {
      input[i] = tolower(input[i]);
    }

    // remove input spaces
    input.erase(remove(input.begin(), input.end(), ' '), 
      input.end());

    // check which fraction should be changed
    selectedFraction = input.at(0);
    input.erase(0,1);

    // remove = sign
    int equals_place = input.find('=');
    if (equals_place != string::npos)
    {
      input.erase(equals_place, equals_place + 1);
    }
    
    // update fraction specified
    if (selectedFraction == 'a')
    {
      input >> a;
    }
    else if (selectedFraction == 'b')
    {
      input >> b;
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
