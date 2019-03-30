/*
  Matrix Implementation in C++
  @author Sachin Singh
*/

#ifndef MATRIX_H_
#define MATRIX_H_
enum MatrixType
{
  EMPTY,
  IDENTITY,
  SCALAR
};

class MatrixOrder
{
public:
  const int ROWS;
  const int COLUMNS;

  MatrixOrder();
  MatrixOrder(int row, int col);
  MatrixOrder(int square_size);
};

class Matrix
{
private:
  int **matrix;
  const MatrixOrder order;

public:
  Matrix(MatrixOrder matrix_order, MatrixType matrix_type, int scalar_value = 0);
  void set_value(int row, int col, int value);
  int get_value(int row, int col);
  Matrix operator+(const Matrix &other);
  Matrix operator-(const Matrix &other);
  Matrix operator*(const Matrix &other);

  void print();
};

#endif