#include "Poly.h"
using namespace std;

Poly::Poly() 
{
    this->size = 1;
    coeffPtr = new int[this->size];
    coeffPtr[0] = 0;
}

Poly::Poly(int coeff) 
{
    this->size = 1;
    coeffPtr = new int[this->size];
    coeffPtr[0] = coeffPtr[coeff];
}

Poly::Poly(int coeff, int pow) 
{
    this->size = pow + 1;
    coeffPtr = new int[this->size];
    
    for(int i = 0; i < this->size; i++) 
    {
        coeffPtr[i] = 0;
    }

    coeffPtr[pow] = coeff;
}

Poly::~Poly() 
{

    delete[] coeffPtr;

    coeffPtr = nullptr;
}

Poly::Poly(const Poly& other) 
{
    
}

void Poly::copy(const Poly& other) 
{
    
}
void Poly::setCoeff(int coeff, int pow) 
{
    if(pow >= 0 ) 
    {
        if(pow < this->size)
        {
            coeffPtr[pow] = coeff;
        }
        else 
        {
            int* temp = new int[pow+1];

            for(int i =0; i < this->size; i++)
            {
                temp[i] = coeffPtr[i];
            }

            for(int k = this->size; k < pow + 1; k++) 
            {
                temp[k] = 0;
            }

            temp[pow] = coeff;

            delete[] coeffPtr;
            coeffPtr = nullptr;
            coeffPtr = temp;
            temp = nullptr;
            this->size = pow + 1;   
        }
    }
}

int Poly::getCoeff(int pow) 
{
    int returnVal = 0;

    if(pow >= 0) 
    {
        if(coeffPtr[pow])
        {
            returnVal = coeffPtr[pow];
        }
    }
    
    return returnVal;
}

ostream& operator<<(ostream& out, Poly& other) 
{
    bool zero = true;

    for(int i = other.size -1; i >=0; i--) 
    {
        if(other.coeffPtr[i] != 0) 
        {
            zero = false;
            out << " ";

            if(other.coeffPtr[i] > 0) 
            {
                out << "+";
            }
            else
            {
                out << "-";
            }

            out << other.coeffPtr[i];

            if(i != 0 && i != 1) 
            {
                out << "x^" << i;
            }
            if(i == 1) 
            {
                out <<"x";
            }
        }   
    }

    if(zero) 
    {
        return out << "0";
    }
    else 
    {
        return out;
    }
}