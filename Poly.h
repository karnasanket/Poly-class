// ------------------------------------------------ Poly.h -------------------------------------------------------

// Name: Sanket Karna, CSS343 B
// April 2
// April 8
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This file is a header class with headers for the methods and functions that represent a polynomial without 
// any negative exponenets. With the combinations of different constructors, methods and mathematical operators,
// the user is able to experience a at hand Polynomial calculator. These polynomials are stored in a dynamically allocated
// array. The purpose of this assignment is to work with allocating and deallocating memory as needed, to learn memroy
// management.
// --------------------------------------------------------------------------------------------------------------------
// Assumptions -  There may not be any negative exponents. The data entered must be integers.
//
// USING C++11
// -------------------------------------------------------------------------------------------------------------------- 

#pragma once 

#include <iostream>

using namespace std; 

class Poly {
    
    // overloaded cout<< operator to print out the values of the Poly object
    friend ostream& operator<<(ostream& out, Poly& other);

    // overloaded cin>> operator for the user to input their own set of Polynomials
    friend istream& operator>>(istream& in, Poly& other);
    
    private:
        // member variables
        int* coeffPtr;
        int size;

    public:
        // constructor and destructor
        Poly();
        Poly(int coeff, int pow);
        Poly(int coeff); 
        Poly(const Poly& other);   
        ~Poly();

        // accessor methods and helper methods
        int getCoeff(int pow);
        void setCoeff(int coeff, int pow);
        void copy(const Poly& other);

        // assignment operator, completing the rule of 3
        Poly& operator=(const Poly& other);

        // mathematical operators
        Poly operator+(const Poly& other) const;
        Poly operator-(const Poly& other) const;
        Poly operator*(const Poly& other) const;
        Poly& operator+=(const Poly& other);
        Poly& operator-=(const Poly& other);
        Poly& operator*=(const Poly& other);
        bool operator==(const Poly& other) const;
        bool operator!=(const Poly& other) const;  

};

