/**
 * FERRER, Matt Brycen L.
 * ENGG 31 - J
 * Project 3
 * mmult.cpp
*/

#include "matrix.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
  string input_name_1, input_name_2, output_name;

  // parse command line input
  if (argc > 4)  // too many command line arguments = invalid
  {
    cout << "Too many inputs entered. "
      << "Please enter command arguments in the format: "
      << "mmult matrix-file-1 matrix-file-2 [output-file]\n";
    return 0;
  }

  else if (argc == 4)  // output-file specified
  {
    input_name_1 = argv[1];
    input_name_2 = argv[2];
    output_name = argv[3];
  }
  else if (argc == 3)  // no output-file specified
  {
    input_name_1 = argv[1];
    input_name_2 = argv[2];
    output_name = "mproduct.txt";  // default output file name
  }
  else  // less than 2 command line arguments = invalid
  {
    cout << "Please enter two matrix filenames.\n";
    return 0;
  }

  // process matrices from input files
  Matrix a, b;
  try
  {
    a = import_from_matrix_file(input_name_1);
    b = import_from_matrix_file(input_name_2);

    // print information about input matrices
    cout << "Input Matrices: " << endl;
    cout << input_name_1 << " (size " << a.getRows() << "x" << 
      a.getColumns() << ")"<< endl;
    cout << input_name_2 << " (size " << b.getRows() << "x" << 
      b.getColumns() << ")\n" << endl;
  }
  catch (int num)  // invalid filename
  {
    cout << "Invalid filename." << endl;
    return 0;
  }

  // calculate product of matrices a and b
  try
  {
    Matrix c;
    c = a * b;

    // print information about product matrix
    cout << "Product matrix: " << endl;
    cout << output_name << " (size " << c.getRows() << "x" << 
      c.getColumns() << ")" << endl;

    // export to output file
    cout << "Product exported to file " << output_name << endl;
    c.export_to_matrix_file(output_name);
  }

  catch (int num)  // invalid matrix multiplication sizes
  {
    cout << "Matrix multiplication not possible." << endl;
  }

  return 0;
}
