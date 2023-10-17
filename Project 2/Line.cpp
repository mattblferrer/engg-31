/**
 * FERRER, Matt Brycen L.
 * ENGG 31 - J
 * Project 2
 * Line.cpp
*/

#include "Line.h"
#include "Solution.h"
#include <cmath>
#include <iostream>

using namespace std;

// initializes default line to y = 0 if not specified
Line::Line()
{
  a = 0;
  b = 1;
  c = 0;
}

// initializes line that passes through coordinates (x1, y1) and 
// (x2, y2) and stores it in form ax + by = c
Line::Line(double x1, double y1, double x2, double y2)
{
  // calculate standard form ax + by = c of lines
  a = y2 - y1;
  b = x1 - x2;
  c = x1 * a + y1 * b;

  // scale such that a^2 + b^2 = 1 and a is positive
  double L_scaling;
  if (a < 0)
  {
    L_scaling = sqrt(a * a + b * b);
  }
  else
  {
    L_scaling = -sqrt(a * a + b * b);
  }

  a = a / L_scaling;
  b = b / L_scaling;
  c = c / L_scaling;
}

// overloads the = operator
Line& Line::operator=(const Line& L)
{
  a = L.a;
  b = L.b;
  c = L.c;

  return *this;
}

// overloads the && operator and returns the solution of a linear
// system of two lines
Solution Line::operator&&(const Line& L) const
{
  double x1, x2, x3, x4, y1, y2, y3, y4;
  double eps = 1e-12;   // epsilon for double calculations

  // find two points on line L1
  if (b == 0)  // vertical L1
  {
    x1 = c / a;
    y1 = 0;
    x2 = c / a;
    y2 = 1;
  }
  else  // non-vertical L1
  {
    x1 = 0;
    y1 = c / b;
    x2 = 1;
    y2 = (c - a) / b;
  }

  // find two points on line L2
  if (L.b == 0)  // vertical L2
  {
    x3 = L.c / L.a;
    y3 = 0;
    x4 = L.c / L.a;
    y4 = 1;
  }
  else  // non-vertical L2
  {
    x3 = 0;
    y3 = L.c / L.b;
    x4 = 1;
    y4 = (L.c - L.a) / L.b;
  }

  // calculate determinants
  double denominator = (x1 - x2) * (y3 - y4) - 
    (x3 - x4) * (y1 - y2);
  double det_x = (x1 * y2 - x2 * y1) * (x3 - x4) - (x1 - x2) *
    (x3 * y4 - y3 * x4);
  double det_y = (x1 * y2 - x2 * y1) * (y3 - y4) - (y1 - y2) *
    (x3 * y4 - y3 * x4);

  // if denominator < epsilon, lines are coincident or parallel
  if (abs(denominator) < eps)
  {
    // L1 and L2 coincident 
    if ((abs(a - L.a) < eps) && (abs(b - L.b) < eps) && 
      (abs(c - L.c) < eps))
    {
      return Solution(a, b, c);  // return points of line L1
    }

    // L1 and L2 parallel but not coincident
    else
    {
      return Solution(0,0,0);  // empty set
    }
    
  }

  // else, lines meet at a single intersection point
  else
  {
    // calculate intersection point (Px, Py)
    double Px = det_x / denominator;
    double Py = det_y / denominator;

    // return solution defined by the point (Px, Py)
    return Solution(Px, Py);
  }
}

// overload the insertion << operator
ostream& operator<<(ostream& output, const Line& L)
{
  // process and format output
  if (L.a != 0)  // nonzero a
  {
    if (L.b < 0)  // negative b
    {
      output << L.a << "x - " << abs(L.b) << "y = " << L.c;
    }
    else
    {
      if (L.b == 0)  // zero b
      {
        output << L.a << "x = " << L.c;
      }
      else  // positive b
      {
        if (L.b == 1)
        {
          output << L.a << "x + y = " << L.c;
        }
        else
        {
          output << L.a << "x + " << L.b << "y = " << L.c;
        }
      }
    }
  }
  else  // zero a
  {
    if (L.b == 1)
    {
      output << "y = " << L.c;
    }
    else
    {
      output << L.b << "y = " << L.c;
    }
  }
  
  return output;
}
