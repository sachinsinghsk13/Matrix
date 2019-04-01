#include <iostream>
#include "matrix.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout << "ORDER OF FIRST MATRIXF? : ";
    int m, n;
    cin >> m >> n;
    cout << "ENTER MATRIX VALUES BELOW : " << endl;
    MatrixOrder o1(m, n);
    Matrix first(o1);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int value;
            cin >> value;
            first.set_value(i, j, value);
        }
    }

    first.print();
    cout << "ORDER OF SECOND MATRIX? : ";
    cin >> m >> n;
    cout << "ENTER MATRIX VALUES BELOW : " << endl;
    MatrixOrder o2(m, n);
    Matrix second(o2);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int value;
            cin >> value;
            second.set_value(i, j, value);
        }
    }
    second.print();
    cout << "Multiplication OF BOTH MATRIX" << endl;
    Matrix sum = second * first;
    sum.print();
    return 0;
}
