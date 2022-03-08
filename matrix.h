#ifndef MATRIX_H
#define MATRIX_H

#include <memory>
#include <iostream>

struct MatrixDiffSizeException: public std::exception{
    const char* what() const throw(){
        return "Matrix +/-: operation is not possible -  Sizes of Matrices are not the same";
    }
};

struct MatrixNotMultiplicable: public std::exception{
    const char* what() const throw(){
        return "Matrix *: A*B operation is not possible -  columns of A != rows of B";
    }
};


class Matrix
{
private:
    int m_rows;
    int m_columns;
    std::unique_ptr<double[]>  m_data;
public:
    Matrix(int rows, int columns);
    Matrix(const Matrix& rhs);
    Matrix(Matrix&& other) noexcept;

    double& operator[](std::size_t idx);
    const double& operator[](std::size_t idx) const;
    Matrix& operator+= (const Matrix& rhs);
    Matrix& operator-= (const Matrix& rhs);
    friend Matrix operator+ (Matrix lhs, const Matrix& rhs){ return lhs += rhs; }
    friend Matrix operator- (Matrix lhs, const Matrix& rhs){ return lhs -= rhs; }
    friend Matrix operator* (Matrix& lhs, const Matrix& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& rhs);
};


#endif /* MATRIX_H */