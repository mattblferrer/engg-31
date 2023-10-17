/**
 * FERRER, Matt Brycen L.
 * ENGG 31 - J
 * Project 2
 * Solution.cpp
*/

#include "Line.h"
#include "Solution.h"
#include <iostream>

using namespace std;

// initializes solution to point (0, 0)
Solution::Solution()
{
  is_parallel_coincident = false;
  a = 0;
  b = 0;
  c = 0;
}

// initializes solution based on point coordinates (x_in, y_in)
Solution::Solution(double x_in, double y_in)
{
  is_parallel_coincident = false;
  a = x_in;
  b = y_in;
  c = 0;
}

// initializes solution for parallel and coincident based on a line
// with standard form ax + by = c or to an empty set with a,b,c = 0
Solution::Solution(double a_in, double b_in, double c_in)
{
  is_parallel_coincident = true;
  a = a_in;
  b = b_in;
  c = c_in;
}

// overload the insertion << operator
ostream& operator<<(ostream& output, const Solution& S)
{
  output << "Solution: ";  // label output
  if (S.is_parallel_coincident)
  {
    // parallel - output empty set
    if ((S.a == 0) && (S.b == 0) && (S.c == 0))
    {
      output << "Empty Set";
    }

    // coincident - output equation of line ax + by = c
    else
    {
      // format line output
      output << "line ";
      if (S.a != 0)  // nonzero a
      {
        if (S.b < 0)  // negative b
        {
          output << S.a << "x - " << abs(S.b) << "y = " << S.c;
        }
        else
        {
          if (S.b == 0)  // zero b
          {
            output << S.a << "x = " << S.c;
          }
          else  // positive b
          {
            output << S.a << "x + " << S.b << "y = " << S.c;
          }
        }
      }
      else  // zero a
      {
        if (S.b == 1)
        {
          output << "y = " << S.c;
        }
        else
        {
          output << S.b << "y = " << S.c;
        }
      }

      output << " (lines are identical)";  // statement of soln
    }
  }

  // neither parallel nor coincident - output point (x, y)
  else
  {
    output << "Point: (" << S.a << ", " << S.b << ")";
  }
  
  return output;
}
