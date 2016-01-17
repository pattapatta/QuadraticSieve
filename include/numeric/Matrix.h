/*
*  This file is part of Quadratic Sieve.
*
*  Quadratic Sieve is free software: you can redistribute it and/or modify it under the terms of 
*  the GNU General Public License as published by the Free Software Foundation, either 
*  version 3 of the License, or (at your option) any later version. Quadratic Sieve is distributed 
*  in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
*  warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General 
*  Public License for more details. You should have received a copy of the GNU General 
*  Public License along with Quadratic Sieve. If not, see http://www.gnu.org/licenses/.
*
*  Author: Ayoub Ouarrak
*/

#ifndef QUADRATIC_SIEVE_MATRIX_GUARD
#define QUADRATIC_SIEVE_MATRIX_GUARD
#include "Vector.h"
#include <string>

namespace QS {
namespace numeric {

template <class T>
class Matrix {

private:
    Vector<Vector<T>> _matrix;
    std::size_t _rows;
    std::size_t _cols;

protected:
    bool rangeCheck(std::size_t index);
    bool rangeCheck(std::string range);

public:
    Matrix();
    Matrix(std::size_t rows, std::size_t cols, const T& _initial);
    Matrix(const Matrix<T>& rhs);
    virtual ~Matrix();

    // operators overloading
    Matrix<T> operator+(const Matrix<T>& rhs);
    Matrix<T> operator-(const Matrix<T>& rhs);
    Matrix<T> operator*(const Matrix<T>& rhs);

    // scalar operators overloading
    Matrix<T> operator+(const T& rhs);
    Matrix<T> operator-(const T& rhs);
    Matrix<T> operator*(const T& rhs);
    Matrix<T> operator/(const T& rhs);

    vector<T> operator*(const vector<T>& rhs);

    // assignment operator
    Matrix<T>& operator=(const Matrix<T>& rhs);

    // slice the matrix from row1 to row2 or , the range is expressed like "n:m"
    Matrix<T> operator[](std::string range);

    // return a row from the matrix, if index is negative return the col
    // eg: v[4] return the 4th row, v[-4] return the 4th col
    Vector<T> operator[](signed long index);

    // return a row from the matrix, if index is negative return the col (read only)
    const Vector<T>& operator[](signed long index) const;

    // access element operator overloading
    T& operator()(std::size_t row, std::size_t col);

    // access element operator (read only)
    const T& operator()(std::size_t row, std::size_t col) const;

    // return the number of rows
    std::size_t rows() const;
    // return the number fo cols
    std::size_t cols() const;

    // return the transposed matrix
    Matrix<T> transpose();

    // find a element in the matrix and the return the index i and j 
    std::make_pair<std::size_t, std::size_t> find(const T& f) const;

    // swap two rows in the matrix
    void swapR(const Vector<T>& row1, const Vector<T>& row2);
    // swap two cols in the matrix
    void swapC(const Vector<T>& col1, const Vecotr<T>& col2);
    // swap two elemements in the matrix
    void swap(std::size_t row1, std::size_t col1, std::size_t row2, std::size_t col2);
};

}
}
#endif