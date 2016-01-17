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

#ifndef QUADRATIC_SIEVE_Z2MATRIX_GUARD
#define QUADRATIC_SIEVE_Z2MATRIX_GUARD
#include "Matrix.h"
#include <bitset>

namespace QS {
namespace numeric {

template <class T, std::size_t cols>
class Z2Matrix : public Matrix<T> {
private:
    vector<std::bitset<cols>> _bits;

public:
    Z2Matrix();
    Z2Matrix(const Z2Matrix<cols>& rhs);
    explicit Z2Matrix(std::size_t rows);
    explicit Z2Matrix(const Matrix<T>& rhs);
    virtual ~Z2Matrix();

    // flip the bit in position row, col 
    void flip(std::size_t row, std::size_t col);

    // set to 1 the bit in position row, col
    void set(std::size_t row, std::size_t col);

    // set to 0 the bit in position row, col
    void reset(std::size_t row, std::size_t col);

    // count the number of 1 in a row, if index is negative count the 1 in a col
    std::size_t count(size_t index) const;

    // check if two row are equal
    bool check(const std::bitset<cols>& row1, const std::bitset<cols>& row2) const;

    // reduce matrix using gauss elimination
    Z2Matrix<cols> reduce();
    
    // AND bitwise operator overloading
    Z2Matrix<cols> operator&(const Z2Matrix<cols>& rhs) const; 
    // NOT bitwise operator overloading
    Z2Matrix<cols> operator~(const Z2Matrix<cols>& rhs) const; 
    // XOR bitwise operator overloading
    Z2Matrix<cols> operator^(const Z2Matrix<cols>& rhs) const; 
    // OR bitwise operator overloading
    Z2Matrix<cols> operator|(const Z2Matrix<cols>& rhs) const; 
};


}
}

#endif