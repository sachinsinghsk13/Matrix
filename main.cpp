#include <iostream>
#include "matrix.h"
using namespace std;


int main(int argc, char *argv[])
{
    SquareMatrixOrder order(10);
    Matrix m(order, 110);
    m.print();
    return 0;
}
