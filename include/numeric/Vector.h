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
#include <string>

namespace QS {
namespace numeric {

template <class T>
class Vector {

private:
    T* _component;
    std::size_t _size;

protected:
    bool rangeCheck(std::size_t index);
    bool rangeCheck(std::string range);

public:
    Vector();
    virtual ~Vector();
    explicit Vector(std::size_t size);
    Vector(const Vector<T>& v);
    Vector(std::size_t size, const T& initValue);

    // return the size of the vector
    std::size_t size() const;
    
    // find a element in the vector and return the index
    std::size_t find(const T& f) const;

    // slice the vector from n to m, the range is a string with the following syntax "n:m"
    Vector<T> operator[](std::string range);

    // access operators overloading
    T& operator[](std::size_t index);

    // access operator (only read mode)
    const T& operator[](std::size_t index) const;

    // assignment operator
    Vector<T>& operator=(const Vector<T>& rhs);

    // vector-vector operators overloading
    Vector<T> operator+(const Vector<T>& rhs);
    Vector<T> operator-(const Vector<T>& rhs);
    Vector<T> operator*(const Vector<T>& rhs);

    // scalar-vector operators overloading
    Vector<T> operator+(const T& rhs);
    Vector<T> operator-(const T& rhs);
    Vector<T> operator*(const T& rhs);
    Vector<T> operator/(const T& rhs);

    // Iterators definition
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

public:
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

}
}

#endif
