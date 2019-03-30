#include <iostream>
#include "matrix.h"
using namespace std;


Matrix::Matrix(int row, int col, Type type) : ROW(row), COL(col)
{
    if (row > 0 && col > 0)
    {
        matrix = new int *[ROW];
        for (int i = 0; i < ROW; i++)
        {
            *(matrix + i) = new int[COL];
        }
        /* Make an Empty matrix*/
        if (type == Type::EMPTY)
        {
            for (int i = 0; i < ROW; i++)
            {
                for (int j = 0; j < COL; j++)
                {
                    *(*(matrix + i) + j) = 0;
                }
            }
        } else if (type == Type::IDENTITY) {
            for (int i = 0; i < ROW; i++)
            {
                for (int j = 0; j < COL; j++)
                {
                    *(*(matrix + i) + j) = (i == j)?1:0;
                }
            }
        }
    }
    else
    {
        cout << "Negetive Row or Column" << endl;
        delete this;
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