#include <iostream>
#include "matrix.h"
using namespace std;

MatrixOrder::MatrixOrder() : ROWS(1), COLUMNS(1) {}
MatrixOrder::MatrixOrder(int row, int col) : ROWS((row > 0) ? row : throw invalid_argument("row value must be positive and not zero")),
                                             COLUMNS((col > 0) ? col : throw invalid_argument("column value must be positive and not zero")) {}

MatrixOrder::MatrixOrder(const MatrixOrder &mo) : MatrixOrder(mo.ROWS, mo.COLUMNS) {}

bool operator==(const MatrixOrder &order1, const MatrixOrder &order2)
{
    return order1.ROWS == order2.ROWS && order1.COLUMNS == order2.COLUMNS;
}

SquareMatrixOrder::SquareMatrixOrder(int square_size) : MatrixOrder(square_size, square_size) {}

Matrix::Matrix(MatrixOrder order) : ORDER(order)
{
    // Allocate Memory for Rows
    matrix = new int *[ORDER.ROWS];

    // Allocate Memory for Columns
    for (int i = 0; i < ORDER.ROWS; i++)
    {
        *(matrix + i) = new int[ORDER.COLUMNS];
    }

    // Initialize Matrix (set value zero to each cell)
    for (int i = 0; i < ORDER.ROWS; i++)
    {
        for (int j = 0; j < ORDER.COLUMNS; j++)
        {
            *(*(matrix + i) + j) = 0;
        }
    }
}

Matrix::Matrix(SquareMatrixOrder order, int scalar_value) : ORDER(order)
{
    // Allocate Memory for Rows
    matrix = new int *[ORDER.ROWS];

    // Allocate Memory for Columns
    for (int i = 0; i < ORDER.ROWS; i++)
    {
        *(matrix + i) = new int[ORDER.COLUMNS];
    }

    // Initialize Matrix (set value zero to each cell)
    for (int i = 0; i < ORDER.ROWS; i++)
    {
        for (int j = 0; j < ORDER.COLUMNS; j++)
        {
            *(*(matrix + i) + j) = (i == j) ? scalar_value : 0;
        }
    }
}

void Matrix::set_value(int row, int col, int item)
{
    if (row >= 0 && row <= (ORDER.ROWS - 1) && col >= 0 && col <= (ORDER.COLUMNS - 1))
    {
        *(*(matrix + row) + col) = item;
    }
    else
        throw invalid_argument("order out of range for this matrix");
}

int Matrix::get_value(int row, int col)
{
    if (row >= 0 && row <= (ORDER.ROWS - 1) && col >= 0 && col <= (ORDER.COLUMNS - 1))
    {
        return *(*(matrix + row) + col);
    }
    else
    {
        cout << "Invalid Coordinate" << endl;
        return -1;
    }
}

void Matrix::print()
{
    for (int i = 0; i < ORDER.ROWS; i++)
    {
        for (int j = 0; j < ORDER.COLUMNS; j++)
        {
            cout.width(5);
            cout.setf(ios::left);
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
}

Matrix operator+(Matrix &matrix1, Matrix &matrix2)
{
    if (matrix1.ORDER == matrix2.ORDER)
    {
        MatrixOrder mo(matrix1.ORDER);
        Matrix matrix(mo);
        for (int i = 0; i < matrix1.ORDER.ROWS; i++)
        {
            for (int j = 0; j < matrix1.ORDER.COLUMNS; j++)
            {
                int sum = matrix1.get_value(i, j) + matrix2.get_value(i, j);
                matrix.set_value(i, j, sum);
            }
        }
        return matrix;
    }
    else
        throw invalid_argument("Matrix order are not same");
}

Matrix operator-(Matrix &matrix1, Matrix &matrix2)
{
    if (matrix1.ORDER == matrix2.ORDER)
    {
        MatrixOrder mo(matrix1.ORDER);
        Matrix matrix(mo);
        for (int i = 0; i < matrix1.ORDER.ROWS; i++)
        {
            for (int j = 0; j < matrix1.ORDER.COLUMNS; j++)
            {
                int sum = matrix1.get_value(i, j) - matrix2.get_value(i, j);
                matrix.set_value(i, j, sum);
            }
        }
        return matrix;
    }
    else
        throw invalid_argument("Matrix order are not same");
}

Matrix operator*(Matrix &first, Matrix &second)
{
    if (first.ORDER.COLUMNS == second.ORDER.ROWS) {
        MatrixOrder order(first.ORDER.ROWS, second.ORDER.COLUMNS);
        Matrix result(order);
        int sum = 0;
        for (int i = 0 ; i < first.ORDER.ROWS; i++) {
            for (int j = 0 ; j < second.ORDER.COLUMNS; j++) {
                for (int k = 0; k < first.ORDER.COLUMNS; k++) {
                    sum += first.get_value(i, k) * second.get_value(k, j);
                }
                result.set_value(i, j, sum);
                sum = 0;
            }
        }
        return result;
    }
    else {
        throw invalid_argument("Matrices are not multiplacable");
    }
}

Matrix operator*(int value, Matrix &matrix)
{
    MatrixOrder mo(matrix.ORDER);
    Matrix m(mo);
    for (int i = 0; i < matrix.ORDER.ROWS; i++)
    {
        for (int j = 0; j < matrix.ORDER.COLUMNS; j++)
        {
            m.set_value(i, j, value * matrix.get_value(i, j));
        }
    }
    return m;
}