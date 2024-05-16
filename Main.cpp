#include <iostream>
#include "Matrix.hpp"

using std::cin, std::cout;
int main()
{

    // size_t rows1, cols1, rows2, cols2;
    // cout << "Rows & Columns (1 e 2): ";
    // cin >> rows1 >> cols1 >> rows2 >> cols2;

    // Matrix<int> matrix1(rows1, cols1);
    // Matrix<int> matrix2(rows2, cols2);
    // matrix1.fill();
    // matrix2.fill();

    // Matrix<int> product(rows1, cols2);

    // try
    // {
    //     product.multiply(matrix1, matrix2);
    //     product.print();
    // }
    // catch (const std::exception& e)
    // {
    //     std::cerr << "Eccezione: " << e.what() << std::endl;
    // }

    Matrix<int> matrix1(1, 1);
    Matrix<int> matrix2(2, 2);
    matrix1.fill();
    matrix2.fill();

    std::cout << (matrix1!=matrix2) << std::endl;

    return 0;
}
