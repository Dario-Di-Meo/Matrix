#include <iostream>
#include "Matrix.hpp"

using std::cin, std::cout;
int main()
{

    size_t rows, cols;
    cout << "Rows & Columns: ";
    cin >> rows >> cols;

    Matrix<int> matrix(rows, cols);
    matrix.fill();
    matrix.print();

    return 0;
}
