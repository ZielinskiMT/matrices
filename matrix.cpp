#include "matrix.h"


Matrix::Matrix(int rows, int columns):
    m_rows(rows),
    m_columns(columns)
{
    m_data = std::make_unique<double[]>(m_rows * m_columns);
}

Matrix::Matrix(const Matrix& rhs):
    m_rows(rhs.m_rows),
    m_columns(rhs.m_columns)
{
    m_data = std::make_unique<double[]>(m_rows * m_columns);
    for(int i = 0; i < (m_rows * m_columns); i++){
        m_data[i] = rhs.m_data[i];
    }
}

Matrix::Matrix(Matrix&& other) noexcept:
    m_rows(std::exchange(other.m_rows, 0)),
    m_columns(std::exchange(other.m_columns, 0)),
    m_data(std::move(other.m_data))
{}


double& Matrix::operator[](std::size_t idx){
    if(idx >= (m_rows * m_columns))
        throw std::out_of_range("Matrix[idx]: idx out of range");
    return m_data[idx]; 
}

const double& Matrix::operator[](std::size_t idx) const {
    if(idx >= (m_rows * m_columns))
        throw std::out_of_range("Matrix[idx]: idx out of range");
    return m_data[idx];
}


Matrix& Matrix::operator+= (const Matrix& rhs){

    if((m_rows * m_columns) != (rhs.m_rows * rhs.m_columns))
        throw MatrixDiffSizeException();

    for(int i = 0; i < (m_rows * m_columns); i++){
        m_data[i] += rhs.m_data[i];
    }
    return *this;
}

Matrix& Matrix::operator-= (const Matrix& rhs){

    if((m_rows * m_columns) != (rhs.m_rows * rhs.m_columns))
        throw MatrixDiffSizeException();

    for(int i = 0; i < (m_rows * m_columns); i++){
        m_data[i] -= rhs.m_data[i];
    }
    return *this;
}

Matrix operator* (Matrix& lhs, const Matrix& rhs){

    if(lhs.m_columns != rhs.m_rows)
        throw MatrixNotMultiplicable();

    Matrix m_result(lhs.m_rows, rhs.m_columns);

    for(int r = 0; r < m_result.m_rows; r++){
        for(int c = 0; c < m_result.m_columns; c++){
            double result = 0.0;
            for(int i = 0; i < lhs.m_columns; i++){
                result += lhs[r + i] * rhs[i * rhs.m_columns];
            }
            m_result[r * m_result.m_columns + c] = result;
        }
    }
    
    return m_result;
}

std::ostream& operator<<(std::ostream& os, const Matrix& rhs){
    for(int r = 0; r < rhs.m_rows; r++){
        os << "| ";
        for(int c = 0; c < rhs.m_columns; c++)
            os << "\t" << rhs.m_data[r * rhs.m_columns + c];
        os << "\t|\n";
    }
    return os;
}