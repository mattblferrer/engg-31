/**
 * FERRER, Matt Brycen L.
 * ENGG 31 - J
 * Project 3
 * matrix.h
*/

#ifndef MATRIX_CLASS
#define MATRIX_CLASS

#include <string>

class Matrix
{
  private:
    double* pointer;
    int rows;
    int cols;

  public:
    Matrix();
    Matrix(double* pointer_in, int rows_in, int cols_in);
    int getRows() const;
    int getColumns() const;
    Matrix& operator=(const Matrix& M);
    Matrix operator*(const Matrix& M) const;
    void export_to_matrix_file(std::string filename);
};

Matrix import_from_matrix_file(std::string filename);

#endif  // MATRIX_CLASS
