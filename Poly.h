#pragma once 

#include <iostream>

using namespace std; 

class Poly {
    
    friend ostream& operator<<(ostream& out, Poly& other);
    // friend istream& operator>>(istream& in, Poly& other);
    
    private:
        int* coeffPtr;
        int size;

    public:
        Poly();
        Poly(int coeff, int pow);
        Poly(int coeff); 
        Poly(const Poly& other);   
        ~Poly();

        int getCoeff(int pow);
        void setCoeff(int coeff, int pow);
        void copy(const Poly& other);
        // Poly& operator=(const Poly& other);
        // Poly operator+(const Poly& other) const;
        // Poly operator-(const Poly& other) const;
        // Poly operator*(const Poly& other) const;
        
        // Poly& operator+=(const Poly& other);
        // Poly& operator-=(const Poly& other);
        // Poly& operator*=(const Poly& other);
        // bool operator==(const Poly& other) const;
        // bool operator!=(const Poly& other) const;  

};

#include "Poly.cpp"