#include <iostream>
#include "matrix.h"
using namespace std;

MatrixOrder::MatrixOrder() : ROWS(1), COLUMNS(1) {}
MatrixOrder::MatrixOrder(int row, int col) : ROWS((row > 0) ? row : throw invalid_argument("row value must be positive and not zero")),
                                             COLUMNS((col > 0) ? col : throw invalid_argument("column value must be positive and not zero")) {}
MatrixOrder::MatrixOrder(int square_size) : ROWS((square_size > 0 ? square_size : throw invalid_argument("square matrix size must be postive and not zero"))), COLUMNS(ROWS) {}

Matrix::Matrix(MatrixOrder matrix_order, MatrixType matrix_type, int scalar_value)
{
    // Allocate memory for matrix
    matrix = new int *[matrix_order.ROWS];
    for (int i = 0; i < matrix_order.ROWS; i++)
    {
        *(matrix + i) = new int[matrix_order.ROWS];
    }

    // Initialize Matrix
    switch (matrix_type)
    {
    case IDENTITY:
        for (int i = 0; i < matrix_order.ROWS; i++)
        {
            for (int j = 0; j < matrix_order.COLUMNS; j++)
            {
                *(*(matrix + i) + j) = (i == j) ? 1 : 0;
            }
        }
        break;
    case SCALAR:
        for (int i = 0; i < matrix_order.ROWS; i++)
        {
            for (int j = 0; j < matrix_order.COLUMNS; j++)
            {
                *(*(matrix + i) + j) = (i == j) ? scalar_value : 0;
            }
        }
        break;
    default:
        for (int i = 0; i < matrix_order.ROWS; i++)
        {
            for (int j = 0; j < matrix_order.COLUMNS; j++)
            {
                *(*(matrix + i) + j) = 0;
            }
        }
    }
}

void Matrix::set_value(int row, int col, int item)
{
    if (row >= 0 && row <= ROW - 1 && col >= 0 && col <= COL - 1)
    {
        *(*(matrix + row) + col) = item;
    }
    else
    {
        cout << "Invalid Coordinate" << endl;
    }
}

int Matrix::get_value(int row, int col)
{
    if (row >= 0 && row <= (ROW - 1) && col >= 0 && col <= (COL - 1))
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
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout.width(5);
            cout.setf(ios::left);
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
}