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

namespace QS {
namespace Numeric {

template <typename T>
class Matrix {

private:
    Vector<Vector<T> > _matrix;
    std::size_t _rows;
    std::size_t _cols;

public:
    Matrix();
    Matrix(unsigned rows, unsigned cols, const T& _initial);
    Matrix(const Matrix<T>& rhs);
    ~Matrix();

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
    // access element operator overloading
    T& operator()(const unsigned& row, const unsigned& col);
    // access element operator (read only)
    const T& operator()(const unsigned& row, const unsigned& col) const;

    // return the number of rows
    std::size_t rows() const;
    // return the number fo cols
    std::size_t cols() const;
    // find a element in the matrix and the return the index i and j 
    std::make_pair<unsigned, unsigned> find(const T& f) const;
};

}
}
#endif