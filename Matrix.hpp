#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <concepts>

template <typename T>
class Matrix
{
private:

    const size_t rows;
    const size_t cols;
    T** data;

public:

    // Constructor
    Matrix(const size_t& number_of_rows, const size_t& number_of_columns);

    // Equality operator
    bool operator==(const Matrix<T>& matrix) const noexcept;

    // Inequality operator
    bool operator!=(const Matrix<T>& matrix) const noexcept;

    // Fills the matrix with user input
    void fill();

    // Prints the elements of the matrix in a grid
    void print() const;

    // Performs element-wise multiplication of rows and columns
    void multiply(const Matrix<T>& left_matrix, const Matrix<T>& right_matrix) requires std::is_arithmetic_v<T>;

    // Destructor
    ~Matrix();

};

#include "Matrix.cpp"

#endif