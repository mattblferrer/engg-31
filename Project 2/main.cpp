/**
 * FERRER, Matt Brycen L.
 * ENGG 31 - J
 * Project 2
 * main.cpp
*/

#include "Line.h"
#include "Solution.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string> 

using namespace std;

// print available commands and their syntax
void printHelp()
{
  cout << "\nAvailable Commands:\n";
  cout << "help - displays information about the commands ";
  cout << "available and their syntax\n";
  cout << "L1 - selects Line 1 to be modified\n";
  cout << "L2 - selects Line 2 to be modified\n";
  cout << "exit - exits the program\n\n";
}

// checks if string is a valid double
bool is_double(string const& str)
{
  double d;
  istringstream iss = istringstream(str);
  iss >> d;
   
  return !iss.fail() && iss.eof();
}

int main()
{
  double x1, y1, x2, y2;
  Line L1, L2;
  Solution soln;
  string input, xy_input; 

  // print opening lines
  cout << "Line Solver\nType help for instructions.\n";

  while (true)
  {
    // take input from user
    input = "";
    cout << setprecision(10);
    cout << "Line 1: " << L1 << endl;
    cout << "Line 2: " << L2 << endl;
    cout << "\n" << (L1 && L2) << endl;  // print solution
    cout << "Enter command: ";
    cin.sync();  
    getline(cin, input); 

    // convert input to lowercase
    for (int i = 0; i < input.length(); i++)
    {
      input[i] = tolower(input[i]);
    }

    // exit command
    if (input == "exit")
    {
      cout << "Exiting program.\n";
      break;
    }
    
    else
    {
      // help command
      if (input == "help")
      {
        printHelp();
      }
      
      else
      {
        // lines L1 or L2 input
        if (input == "l1" || input == "l2")
        {
          // take input from user
          while (1)
          {
            cout << "\nEnter point x1: ";
            getline(cin, xy_input);
            if (is_double(xy_input))
            {
              istringstream iss = istringstream(xy_input);
              iss >> x1;
              break;
            }
            else
            {
              cout << "Invalid input. Please enter valid number.\n";
            }
          }

          while (1)
          {
            cout << "Enter point y1: ";
            getline(cin, xy_input);
            if (is_double(xy_input))
            {
              istringstream iss = istringstream(xy_input);
              iss >> y1;
              break;
            }
            else
            {
              cout << "Invalid input. Please enter valid number.\n";
            }
          }

          while (1)
          {
            cout << "Enter point x2: ";
            getline(cin, xy_input);
            if (is_double(xy_input))
            {
              istringstream iss = istringstream(xy_input);
              iss >> x2;
              break;
            }
            else
            {
              cout << "Invalid input. Please enter valid number.\n";
            }
          }

          while (1)
          {
            cout << "Enter point y2: ";
            getline(cin, xy_input);
            if (is_double(xy_input))
            {
              istringstream iss = istringstream(xy_input);
              iss >> y2;
              break;
            }
            else
            {
              cout << "Invalid input. Please enter valid number.\n";
            }
          }

          // process input to line class
          Line L(x1, y1, x2, y2);  
          if (input == "l1")
          {
            L1 = L;
          }
          else
          {
            L2 = L;
          }
        }

        // invalid input
        else
        {
          cout << "Invalid input. Type help for instructions.\n\n";
        }
      }
    }
  }
  
  return 0;
}
