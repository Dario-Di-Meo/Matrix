// Costruttore
template<typename T>
Matrix<T>::Matrix(const size_t& number_of_rows, const size_t& number_of_columns) : rows(number_of_rows), cols(number_of_columns)
{
    this->matrix = new T*[rows];
    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new T[cols];
    }
}
// Riempie la matrice con l'input dell'utente
template<typename T>
void Matrix<T>::fill()
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << "Matrix[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }
}
// Stampa la matrice
template<typename T>
void Matrix<T>::print() const
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }  
}
// Distruttore
template<typename T>
Matrix<T>::~Matrix()
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            matrix[i][j] = T{};
        }
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr; 
}
