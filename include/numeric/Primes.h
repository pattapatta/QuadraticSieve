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

#ifndef QUADRATIC_SIEVE_PRIME_GUARD
#define QUADRATIC_SIEVE_PRIME_GUARD
#include <iostream>
#include "Vector.h"

namespace QS {
namespace numeric {

template <class T>
class Primes {
private:
    Vector<T> _primes;
    unsigned long _offset;
    unsigned long _bound;

protected:
    // return the next prime number
    unsigned long next();

public:
    Prime();
    Prime(std::size_t bound);
    ~Prime();

    // operator >> that return the next prime
    Prime& operator>>(Prime& stream, unsigned long &p)
};

}
}
#endif
