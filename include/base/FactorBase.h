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

#ifndef QUADRATIC_SIEVE_FACTOR_BASE_GUARD
#define QUADRATIC_SIEVE_FACTOR_BASE_GUARD

#include "../numeric/Prime.h"
#include "../numeric/Vector.h"

namespace QS {
namespace base {

template <class T>
class FactorBase {
private:
    Prime<T> _primes;
    Vector<T> _base;
    vector<T> _solutions;
    std::size_t _size;

    // compute the legendre symbol
    int legendre(long residue) const;

public:
    FactorBase();
    ~FactorBase();
    explicit FactorBase(std::size_t size);
    FactorBase(const FactorBase<T>& b);

    // return the base factor
    Vector<T> base() const;
    // return the solution of the equation "Q(A) = n mod p"
    Vector<T> solutions() const;
    // return size of the factor base
    std::size_t size() const;
};

}
}
#endif