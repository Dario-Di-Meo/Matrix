
// Constructor
template<typename T>
Matrix<T>::Matrix(const size_t& number_of_rows, const size_t& number_of_columns) : rows(number_of_rows), cols(number_of_columns)
{
    data = new T*[rows];
    for (size_t i = 0; i < rows; i++)
    {
        data[i] = new T[cols];
    }
}

// Equality operator
template<typename T>
bool Matrix<T>::operator==(const Matrix<T>& matrix) const noexcept
{
    if ((this->rows == matrix.rows) && (this->cols == matrix.cols))
    {
        bool mismatch = false;
        size_t i = 0;
        while ((i < rows) && (!mismatch))
        {
            size_t j = 0;
            while ((j < cols) && (!mismatch))
            {
                if (this->data[i][j] != matrix.data[i][j])
                {
                    mismatch = true;
                }
                j++;
            }
            i++;
        }
        return !mismatch; 
    }
    else
    {
        return false;
    }  
}

// Inequality operator
template<typename T>
bool Matrix<T>::operator!=(const Matrix<T>& matrix) const noexcept
{
    return !(*this == matrix);
}

// Fills the matrix with user input
template<typename T>
void Matrix<T>::fill()
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << "Matrix[" << i << "][" << j << "] = ";
            std::cin >> data[i][j];
        }
    }
}

// Prints the elements of the matrix in a grid
template<typename T>
void Matrix<T>::print() const
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }  
}

// Performs element-wise multiplication of rows and columns
template<typename T>
void Matrix<T>::multiply(const Matrix<T>& left_matrix, const Matrix<T>& right_matrix) requires std::is_arithmetic_v<T>
{
    if ((this->cols == left_matrix.cols) && (this->rows == right_matrix.rows) && (left_matrix.cols == right_matrix.rows))
    {
        for (size_t i = 0; i < this->rows; i++)
        {
            for (size_t j = 0; j < this->cols; j++)
            {
                this->data[i][j] = 0;
                for (size_t k = 0; k < left_matrix.cols; k++)
                {
                    this->data[i][j] += left_matrix.data[i][k] * right_matrix.data[k][j];                    
                }
            }      
        }
    }
    else
    {
        throw std::invalid_argument("Row or column numbers of involved matrices do not match.");
    }
}

// Destructor
template<typename T>
Matrix<T>::~Matrix()
{
    delete[] data;
    data = nullptr; 
}
