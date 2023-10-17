/**
 * FERRER, Matt Brycen L.
 * ENGG 31 - J
 * Project 2
 * Line.h
*/

#ifndef LINE_CLASS
#define LINE_CLASS

#include <iostream>

class Solution;

class Line
{
  private:
    double a;
    double b;
    double c;

  public:
    Line();
    Line(double x1, double y1, double x2, double y2);
    Line& operator=(const Line& L);
    Solution operator&&(const Line& L) const;
    friend std::ostream& operator<<(std::ostream& output, 
      const Line& L);

};

#endif  // LINE_CLASS
