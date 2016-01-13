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
#ifndef QUADRATIC_SIEVE_MATH_GUARD
#define QUADRATIC_SIEVE_MATH_GUARD
#include <cmath>

namespace QS {
namespace Math {

/**
    Compute the Greatest common divisor through the Euclide algorithm.
    From: Languasco & Zaccagnini, Introduzione alla Crittografia, Hoepli.
    Paragrafo 6.2
*/
long gcd(long a, long b) {
    long unsigned m = std::abs(a);
    long unsigned n = std::abs(b);
    long unsigned r = n;

    while(r != 0) {
        r = m % n;
        m = n;
        n = r;
    }
    return(m);
}

/**
    Compute the Greatest common divisor through the Extended Euclide algorithm.
    From:Languasco & Zaccagnini, Introduzione alla Crittografia, Hoepli.
    Paragrafo 6.2
*/

long gcd(long a, long b, long& lambda, long& mi) {
    long a1 = 1;
    long a2 = 0;
    long b1 = 0;
    long b2 = 1;
    long m = a;
    long n = b;
    long r = n;

    while(r != 0) {
        long q = m / n;
        r = m % n;
        long a3 = a1 - q * a2;
        long b3 = b1 - q * b2;
        a1 = a2;
        a2 = a3;
        b1 = b2;
        b2 = b3;
        m = n;
        n = r;
    }

    lambda = a1;
    mi = b1;
    return(m);
}

/**
    Compute the Product a*m (n) 
    From: Languasco & Zaccagnini, Introduzione alla Crittografia, Hoepli.
    Paragrafo 6.9.1
*/

long modNProduct(long a, long m, long n) {
    long S = 0;
    long M = m;
    long A = a;
    long r, q;
    do {
        r = M % 2;
        q = M / 2;

        if (r == 1) {
            S += A;
            S  = S % n;
        }

        A += A;
        A = A % n;
        M = q;
    } while(q > 0);

    return(S);
}

/**
    Compute the power of a^m (n)
    From:Languasco & Zaccagnini, Introduzione alla Crittografia, Hoepli.
    Paragrafo 6.9.2
*/

long modNPower(long a, long m, long n) {
    long P = 1;
    long M = m;
    long A = a;
    long r;
    long q;
    
    do {
        r = M % 2;
        q = M / 2;
        if (r == 1)
            P = moltiplicazione_mod_n(P,A,n);
            A = moltiplicazione_mod_n(A,A,n);
            M  = q;
    } while(q > 0);

    return(P);
}

/**
    Return the square root downward rounded.
*/
long roundedSqrt(long n) {
    if (n < 0)
        return(-1);
    
    long m = int(sqrt((double) n));
    return(m);
}

/**
    Compute the quotient "q" and the remainder " r" of the division of "N" for "M"
    From: Languasco & Zaccagnini, Introduzione alla Crittografia, Hoepli.
    Paragrafo 6.9.4
*/

std::pair<long, long> division(long N, long M, long d) {
    long m = M - d;
    long max = d > 0 ? M : m;
    long q, r;

    q = N / M;
    r = d * q + (N % M);
    long qq;

    do {
        qq = r / M;
        if (r < 0)
            --qq;

        long rr = r - M * qq;
        q += qq;
        r = d * qq + rr;
    } while ((r < 0) || (r >= max));

    while (r >= m) {
        r -= m;
        ++q;
    }

    return std::make_pair<long, long>(q, r);
}

}
}
#endif