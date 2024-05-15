#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

template <typename T>
class Matrix
{
private:
    size_t rows;
    size_t cols;
    T** matrix;
public:
    // Costruttore
    Matrix(const size_t& number_of_rows, const size_t& number_of_columns);
    // Riempie la matrice con l'input dell'utente
    void fill();
    // Stampa la matrice
    void print() const;
    // Distruttore
    ~Matrix();
};

#endif
