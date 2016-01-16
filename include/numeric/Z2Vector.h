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

#ifndef QUADRATIC_SIEVE_VECTOR_GUARD
#define QUADRATIC_SIEVE_VECTOR_GUARD
#include "Vector.h"
#include <bitset>

namespace QS {
namespace numeric {

template<class T, std::size_t size>
class Z2Vector : public Vector<T> {
private:
    std::bitset<size> _bits;
    std::size_t _size;

public:
    Z2Vector();
    Z2Vector(const Z2Vector<size>& z2v);
    explicit Z2Vector(const Vector<T>& v);
    virtual ~Z2Vector();

    // flip the bit in position index 
    void flip(std::size_t index);

    // set to 1 the bit in position index
    void set(std::size_t index);

    // set to 0 the bit in position index
    void reset(std::size_t index);

    // control if the vector is null
    bool isNull() const;


    // AND bitwise operator overloading
    Z2Vector<size> operator&(const Z2Vector<size>& rhs) const; 
    // NOT bitwise operator overloading
    Z2Vector<size> operator~(const Z2Vector<size>& rhs) const; 
    // XOR bitwise operator overloading
    Z2Vector<size> operator^(const Z2Vector<size>& rhs) const; 
    // OR bitwise operator overloading
    Z2Vector<size> operator|(const Z2Vector<size>& rhs) const; 

};

}
}
#endif