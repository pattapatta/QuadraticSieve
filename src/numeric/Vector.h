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
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cassert>

namespace QS {
namespace Numeric {

template <typename T>
class Vector {
private:
    T* _components;
    unsigned _size;

public:
    Vector();
    ~Vector();
    explicit Vector(unsigned size);
    Vector(unsigned size, T initValue);


    unsigned size() const;
    T& operator[](size_type index);
    const T& operator[](unsigned index) const;

    /**
        Iterators definition
    */
    class iterator {
    private:
        pointer _ptr;

    public:
        typedef iterator self_type;
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef std::forward_iterator_tag iterator_category;
        typedef int difference_type;

        iterator(pointer ptr) : ptr_(ptr) { }
        self_type operator++();
        self_type operator++(int junk);
        reference operator*();
        pointer operator->();
        bool operator==(const self_type& rhs);
        bool operator!=(const self_type& rhs);
    };

    class const_iterator {
    private:
        pointer ptr_;

    public:
        typedef const_iterator self_type;
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef int difference_type;
        typedef std::forward_iterator_tag iterator_category;

        const_iterator(pointer ptr) : ptr_(ptr) { }
        self_type operator++();
        self_type operator++(int junk);
        const value_type& operator*();
        const value_type* operator->();
        bool operator==(const self_type& rhs);
        bool operator!=(const self_type& rhs);
    };

    iterator begin();
    iterator end()
    const_iterator begin() const;
    const_iterator end() const;
};

}
}

#endif
