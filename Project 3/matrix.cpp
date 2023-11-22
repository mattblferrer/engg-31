/**
 * FERRER, Matt Brycen L.
 * ENGG 31 - J
 * Project 3
 * matrix.cpp
*/

#include "matrix.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <iostream>

using namespace std;

// default constructor of matrix
Matrix::Matrix()
{
  // create new array with initial value of 0
  double* arr = new double[1];
  arr[0] = 0.0;

  // assign default pointer and size
  pointer = arr;
  rows = 1;
  cols = 1;
}

// creates a matrix object of size rows_in x cols_in
Matrix::Matrix(double* pointer_in, int rows_in, int cols_in)
{
  pointer = pointer_in;
  rows = rows_in;
  cols = cols_in;
}

// getter for rows value
int Matrix::getRows() const
{
  return rows;
}

// getter for columns value
int Matrix::getColumns() const
{
  return cols;
}

// overloads the = operator by creating a deep copy of the matrix
Matrix& Matrix::operator=(const Matrix& M)
{
  if (this == &M)  // check if same matrix is being passed
  {
    return *this;
  }

  // otherwise, deep copy the array from M and return
  rows = M.rows;
  cols = M.cols;
  pointer = new double[M.rows * M.cols];
  for (int i = 0; i < M.rows * M.cols; i++)
  {
    pointer[i] = M.pointer[i];
  }
  return *this;
}

// computes the product of two matrices and returns a matrix object
// constructed from the product data
Matrix Matrix::operator*(const Matrix& M) const
{
  // check if matrix multiplication can be performed
  if (cols != M.rows)  // invalid
  {
    throw -1;
  } 

  // create new matrix = product of two matrices
  int product_size = rows * M.cols;
  double* product = new double[product_size];

  // for every entry in product matrix (p_row, p_col)
  for (int p_row = 0; p_row < rows; p_row++)
  {
    for (int p_col = 0; p_col < M.cols; p_col++)
    {
      // get sum of a_ik * b_kj where a and b are the two matrices
      double sum = 0;
      for (int k = 0; k < cols; k++)
      {
        sum += pointer[p_row * cols + k]
          * M.pointer[k * M.cols + p_col];
      }
      product[p_row * M.cols + p_col] = sum;  // assign to product
    }
  }

  return Matrix(product, rows, M.cols);
}

// reads a valid Matrix File Format file and returns the matrix
// associated
Matrix import_from_matrix_file(string filename)
{
  // read matrix using input filestream
  ifstream matrix_file;
  string line;
  int matrix_rows = 0;  // number of rows in matrix
  int matrix_cols = 0;  // number of columns in matrix
  vector<double> v; 
  matrix_file.open(filename, ios::in); 

  // check if filename is valid
  if (!matrix_file)
  {
    throw -1;
  }

  // get size of matrix
  while (getline(matrix_file, line))
  {
    double x;  // placeholder
    int line_cols = 0;
    stringstream stream(line);

    while (stream >> x)  // read number of columns
    {
      v.push_back(x);
      line_cols++;
    }

    if (matrix_rows == 0)  // read number of columns from 1st row
    {
      matrix_cols = line_cols;
    }
    else  // 2nd row and beyond
    {
      // if less lines in succeeding rows, break
      if (matrix_cols > line_cols)  
      {
        // remove last row from vector
        for (int i = 0; i < line_cols; i++)  // length of row
        {
          v.pop_back();
        }
        break;
      }
    }

    matrix_rows++;
  }
  matrix_file.close();  // close file stream
  
  // declare matrix of size matrix_rows * matrix_cols
  double* arr = new double[matrix_rows * matrix_cols];

  // move values from vector to array
  for (int i = 0; i < matrix_rows * matrix_cols; i++)
  {
    arr[i] = v[i];
  }
  
  return Matrix(arr, matrix_rows, matrix_cols);
}

// exports the matrix passed in the function to a valid Matrix
// File Format file
void Matrix::export_to_matrix_file(string filename)
{
  ofstream output_file(filename);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      output_file << pointer[cols * i + j] << " \t";
    }
    output_file << "\n";
  }
}
