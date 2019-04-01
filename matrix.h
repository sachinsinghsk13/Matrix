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
  MatrixOrder(const MatrixOrder& mo);
  MatrixOrder(int row, int col);
  friend bool operator==(const MatrixOrder& order1, const MatrixOrder& order2);
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
  friend Matrix operator+(Matrix &matrix1, Matrix& matrix2 );
  Matrix& operator-(const Matrix &other);
  Matrix& operator*(const Matrix &other);

  void print();
};
bool operator==(const MatrixOrder& order1, const MatrixOrder& order2);
Matrix operator+(Matrix &matrix1, Matrix& matrix2);
Matrix operator-(Matrix &matrix1, Matrix& matrix2);
Matrix operator*(Matrix &matrix1, Matrix& matrix2);
Matrix operator*(int value, Matrix& matrix2);

#endif