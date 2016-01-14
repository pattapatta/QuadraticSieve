#Quadratic Sieve

##Introduction
The quadratic sieve algorithm (QS) is an integer factorization algorithm and, in practice, the second fastest method known (after the general number field sieve). It is still the fastest for integers under 100 decimal digits or so, and is considerably simpler than the number field sieve. It is a general-purpose factorization algorithm, meaning that its running time depends solely on the size of the integer to be factored, and not on special structure or properties. It was invented by Carl Pomerance in 1981 as an improvement to Schroeppel's linear sieve (from Wikipedia)
     
Our version of the algorithm is a parallel Object Oriented implementation, written in C++. 

##Usage
This version of the algorithm is command-line software, the parameter are specified when QS is launched.
The parameters that can be specified are:
* Number to be factored
* Number of Processors to use
* Number of Cores to use
* Base Factor 
* Range
* Polynomial to use for the factorization
 

##License
Quadratic Sieve is free software: you can redistribute it and/or modify it under the terms of 
the GNU General Public License as published by the Free Software Foundation, either 
version 3 of the License, or (at your option) any later version. Quadratic Sieve is distributed 
in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General 
Public License for more details. You should have received a copy of the GNU General 
Public License along with Quadratic Sieve. If not, see http://www.gnu.org/licenses/.
    
##Authors
Ayoub Ouarrak,
Lorenzo Pattarini

