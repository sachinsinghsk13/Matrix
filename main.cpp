#include <iostream>
#include "matrix.h"
using namespace std;



int main(int argc, char *argv[])
{
    Matrix m(10, 10, Matrix::IDENTITY);
    m.print();
    return 0;
}
