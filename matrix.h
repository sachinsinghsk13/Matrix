#ifndef MATRIX_H_
#define MATRIX_H_

class Matrix
{
  private:
    int **matrix;
    const int ROW;
    const int COL;
    
  public:
    enum Type
    {
        EMPTY,
        IDENTITY,
        SCALAR
    };
    Matrix(int row, int col, Type type);
    void set_value(int row, int col, int value);
    int get_value(int row, int col);
    bool is_rectangular_matrix();
    bool is_square_matrix();
    bool is_vertical_matrix();
    bool is_horizontal_matrix();
    Matrix operator+(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix operator*(const Matrix& other);


    void print();
};

#endif