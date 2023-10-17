/**
 * FERRER, Matt Brycen L.
 * ENGG 31 - J
 * Project 2
 * Solution.h
*/

#ifndef SOLUTION_CLASS
#define SOLUTION_CLASS

#include <iostream>

class Solution
{
  private:
    bool is_parallel_coincident;
    double a;
    double b;
    double c;

  public:
    Solution();
    Solution(double x_in, double y_in);
    Solution(double a_in, double b_in, double c_in);
    friend std::ostream& operator<<(std::ostream& output, 
      const Solution& S);
    
};

#endif // SOLUTION_CLASS
