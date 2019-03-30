#include <iostream>
#include "matrix.h"
using namespace std;

MatrixOrder::MatrixOrder() : ROWS(1), COLUMNS(1) {}
MatrixOrder::MatrixOrder(int row, int col) : ROWS((row > 0) ? row : throw invalid_argument("row value must be positive and not zero")),
                                             COLUMNS((col > 0) ? col : throw invalid_argument("column value must be positive and not zero")) {}


SquareMatrixOrder::SquareMatrixOrder(int square_size) : MatrixOrder(square_size, square_size) {}


Matrix::Matrix(MatrixOrder order) : ORDER(order) {
    // Allocate Memory for Rows
    matrix = new int*[ORDER.ROWS];

    // Allocate Memory for Columns
    for (int i = 0; i < ORDER.ROWS ; i++) {
        *(matrix + i) = new int[ORDER.COLUMNS];
    }

    // Initialize Matrix (set value zero to each cell)
    for (int i = 0; i < ORDER.ROWS ; i++) {
        for (int j = 0 ; j < ORDER.COLUMNS; j++) {
            *( *(matrix + i) + j ) = 0;
        }
    }

}

Matrix::Matrix(SquareMatrixOrder order, int scalar_value) : ORDER(order) {
    // Allocate Memory for Rows
    matrix = new int*[ORDER.ROWS];

    // Allocate Memory for Columns
    for (int i = 0; i < ORDER.ROWS ; i++) {
        *(matrix + i) = new int[ORDER.COLUMNS];
    }

    // Initialize Matrix (set value zero to each cell)
    for (int i = 0; i < ORDER.ROWS ; i++) {
        for (int j = 0 ; j < ORDER.COLUMNS; j++) {
            *( *(matrix + i) + j ) = (i == j) ? scalar_value : 0;
        }
    }
}

void Matrix::set_value(int row, int col, int item)
{
    if (row >= 0 && row <= (ORDER.ROWS - 1) && col >= 0 && col <= (ORDER.COLUMNS - 1))
    {
        *(*(matrix + row) + col) = item;
    }
    else throw invalid_argument("order out of range for this matrix");
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
        for (int j = 0; j < ORDER.COLUMNS ; j++)
        {
            cout.width(5);
            cout.setf(ios::left);
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
}