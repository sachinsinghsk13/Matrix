/*
  Matrix Implementation in C++
  @author Sachin Singh
*/

#ifndef MATRIX_H_
#define MATRIX_H_

class MatrixOrder
{
public:
  const int ROWS;
  const int COLUMNS;
  MatrixOrder();
  MatrixOrder(int row, int col);
};

class SquareMatrixOrder : public MatrixOrder {
  public:
    SquareMatrixOrder(int size);
};

class Matrix
{
private:
  int **matrix;
public:
  Matrix(MatrixOrder order);
  Matrix(SquareMatrixOrder order, int scalar_value = 0);
  const MatrixOrder ORDER;
  void set_value(int row, int col, int value);
  int get_value(int row, int col);
  Matrix operator+(const Matrix &other);
  Matrix operator-(const Matrix &other);
  Matrix operator*(const Matrix &other);

  void print();
};

#endif