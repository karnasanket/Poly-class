// ------------------------------------------------ Poly.cpp -------------------------------------------------------

// Name: Sanket Karna, CSS343 B
// April 2
// April 8
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This file is an implementation for the methods and functions that represent a polynomial without 
// any negative exponenets. With the combinations of different constructors, methods and mathematical operators,
// the user is able to experience a at hand Polynomial calculator. These polynomials are stored in a dynamically allocated
// array. The purpose of this assignment is to work with allocating and deallocating memory as needed, to learn memroy
// management.
// --------------------------------------------------------------------------------------------------------------------
// Assumptions -  There may not be any negative exponents. The data entered must be integers.
//
// USING C++11
// -------------------------------------------------------------------------------------------------------------------- 
#include "Poly.h"
using namespace std;

// ------------------------------------0 Arguement constructor-----------------------------------------------
// Description: Constructs a Poly object with size 1 and no values in it
// ---------------------------------------------------------------------------------------------------

Poly::Poly() 
{
    this->size = 1; // set size 
    coeffPtr = new int[this->size]; // dynamically alloacte memory
    coeffPtr[0] = 0;
}

// ------------------------------------1 Arguement constructor-----------------------------------------------
// Description: Constructs a Poly object with size 1 and a coefficient, making the coeff be at power 0
// ---------------------------------------------------------------------------------------------------

Poly::Poly(int coeff) 
{
    this->size = 1; //size 1
    coeffPtr = new int[this->size]; // dynamically allocate memory
    coeffPtr[0] = coeff; // set 0th power with the coeff
}

// ------------------------------------2 Arguement constructor-----------------------------------------------
// Description: Constructs a Poly object with size of pow + 1 and sets the largest index (power) with the coeff
// entered.
// ---------------------------------------------------------------------------------------------------

Poly::Poly(int coeff, int pow) 
{
    this->size = pow + 1; // size pow + 1, to ensure that the array is right size since arrays index starts at 0
    coeffPtr = new int[this->size]; // dynmically allocate memory
    
    for(int i = 0; i < this->size; i++) // loop to fill in the array with 0's until the last index
    {
        coeffPtr[i] = 0;
    }

    coeffPtr[pow] = coeff; // set the Power's index with the coeff
}

// ------------------------------------Destructor-----------------------------------------------
// Description: Destroys the Poly object no longer in use and deallocates the memory from the heap
// ---------------------------------------------------------------------------------------------------

Poly::~Poly() 
{

    delete[] coeffPtr; // deletes the pointer

    coeffPtr = nullptr; // points to nothing
}

// -----------------------------------Copy constructor-----------------------------------------------
// Description: Deep copies over the values of a different Poly object to *this. Does so by calling a 
// helper copy() method
// ---------------------------------------------------------------------------------------------------

Poly::Poly(const Poly& other) 
{
    copy(other); // calls the helper method
}

// ------------------------------------copy() helper method-----------------------------------------------
// Description: Deep copies over the value of the rhs Poly object to the lhs poly object
// ---------------------------------------------------------------------------------------------------
void Poly::copy(const Poly& other) 
{

    this->size = other.size; // sets *this size to the rhs size
    coeffPtr = new int[this->size]; // dynamically allocates new memory 

    for(int i =0; i < this->size; i++) // for loop of the size of the array
    {
        coeffPtr[i] = other.coeffPtr[i]; // copy over value by value
    }  

}

// ------------------------------------Set coefficient-----------------------------------------------
// Description: Sets coefficient of the index which is the power in the array
// Power (or the index) cannot be a 0
// If the power is greater than the index, a new array is created with the power, and the values of the
// old array are copied, then the new power's coefficient is set
// ---------------------------------------------------------------------------------------------------
void Poly::setCoeff(int coeff, int pow) 
{
    if(pow >= 0 ) // checks negative
    {
        if(pow < this->size) // if the pow entered is in the range of the array
        {
            coeffPtr[pow] = coeff; // set the coefficient
        }
        else 
        {
            int* temp = new int[pow+1]; // else create a temp array with the size of the temp power + 1 to take into account array index starts at -

            for(int i =0; i < this->size; i++) // for loop to copy over the old array
            {
                temp[i] = coeffPtr[i];
            }

            for(int k = this->size; k < pow + 1; k++) // from the old array's end position to the temp arrays end position
            {
                temp[k] = 0; // fill 0 until the last element
            }

            temp[pow] = coeff; // set the index ( or the power) to the coefficient

            delete[] coeffPtr; // delete old array
            coeffPtr = nullptr;
            coeffPtr = temp; // set it equal to temp array
            temp = nullptr; // free up temp array memeory
            this->size = pow + 1; // re-set the size
        }
    }
}

// ------------------------------------Get coefficient-----------------------------------------------
// Description: Returns the coefficient of the parsed in pow which is represented by the index
// Returns 0 is the power entered is less than 0 (in other words a negative) or out of bounds
// ---------------------------------------------------------------------------------------------------

int Poly::getCoeff(int pow) 
{
    int returnVal = 0; 

    if(pow >= 0) // checks neagtive
    {
        if(coeffPtr[pow]) // if the index exists (not out of bounds)
        {
            returnVal = coeffPtr[pow]; // gets the coeff
        }
    }
    
    return returnVal; // return the coeff
}

// ------------------------------------Assignment operator-----------------------------------------------
// Description: Sets one Poly equal to another Poly. Checks if both poly (lhs and rhs) are the same, then 
// frees up *this, to fill it with the rhs Poly. Does so by calling the copy() helper method
// ---------------------------------------------------------------------------------------------------
Poly& Poly::operator=(const Poly& other) 
{   
    if(*this == other) // checks if lhs and rhs are the same
    {
        return *this; // if so nothing to set, its the same so reutrn *this
    }
    
    delete[] this->coeffPtr; // otherwise delete the current *this
    coeffPtr = nullptr;
    copy(other); // and copy over the rhs to *this
    return *this; // return 
}

// ------------------------------------Mathematical operator +-----------------------------------------------
// Description: Adds two Poly objects and returns it
// ---------------------------------------------------------------------------------------------------

Poly Poly::operator+(const Poly& other) const
{
    if(this->size > other.size) // if lhs size is bigger
    {
        Poly returnValue(0, this->size); // makes a poly object big enough

        for(int i = 0; i < this->size; i++) // runs a loop 
        {
            returnValue.coeffPtr[i] = this->coeffPtr[i]; // to copy over the contents of the bigger Poly to the returnVal poly
        }

        for(int j = 0; j < other.size; j++) // then runs a loop of the smaller array's size
        {
            returnValue.coeffPtr[j] += other.coeffPtr[j]; // to add over the coefficient to the returnVal poly
        }

        return returnValue; // returns the new Poly object
    }
    else // if rhs is bigger or both Poly's are the same size
    {
        Poly returnValue(0, other.size); // makes a Poly big enough

        for(int i =0; i < other.size; i ++) // runs a loop of the big/same size Poly's size
        {
            returnValue.coeffPtr[i] = other.coeffPtr[i]; // copies over the content of the bigger/size same Poly
        }

        for(int j = 0; j < this->size; j++) // runs a loop of the other Poly's size
        {
            returnValue.coeffPtr[j] += this->coeffPtr[j]; // adds the values which are the coefficeint 
        }

        return returnValue; // returns the new Poly object
    }
}

// ------------------------------------Mathematical operator ------------------------------------------------
// Description: Subtracts two Poly objects and returns it
// ---------------------------------------------------------------------------------------------------


Poly Poly::operator-(const Poly& other) const
{
    if(this->size > other.size) // if lhs is the bigger Poly
    {
        Poly returnValue(0, this->size); //makes a poly big enough to store the answer

        for(int i = 0; i < this->size; i++) // runs a loop of the big Poly's size
        {
            returnValue.coeffPtr[i] = this->coeffPtr[i]; // copies over the content of the array
        }

        for(int j = 0; j < other.size; j++) // then runs the loop of the smaller Poly's size
        {
            returnValue.coeffPtr[j] -= other.coeffPtr[j]; // subtracts the coefficients for each indicies, represented as powers
        }

        return returnValue; // returns the answer
    }
    else // if rhs is bigger or they're the same size
    {
        Poly returnValue(0, other.size); // makes a Poly object big enough to store the difference

        for(int i = 0; i < this->size; i ++) // runs a loop of the lhs Poly's size (since its lhs-rhs)
        {
            returnValue.coeffPtr[i] = this->coeffPtr[i]; // copies over the content
        }

        for(int j = 0; j < other.size; j++) // runs a loop of the rhs's Poly's size
        {
            returnValue.coeffPtr[j] -= other.coeffPtr[j]; // subtracts the value of the indicies, represented as powers
        }

        return returnValue; // returns the final answers
    }
}

// ------------------------------------Mathematical operator *-----------------------------------------------
// Description: Multiplies two Poly objects and returns it
// ---------------------------------------------------------------------------------------------------

Poly Poly::operator*(const Poly& other) const
{
    int tempSize = (this->size + other.size) -2; // computing the size for the answer Poly, which is the sum of two largers power multiplied value
                                                 // -2 becuase the size != power. Power can be 7 for both and size would be 8 (because of +1 in constructor)
                                                 // 7+7 =14, but the size 8+8 =16. which should be so, -2 to account for that

    Poly returnVal(0, tempSize); // create the answer poly.

    for(int i = 0; i < this->size; i++) // outsize loops of one of the lhs Poly
    {
        if(this->coeffPtr[i] != 0) // if the coefficient isnt 0
        {
            for(int j = 0; j < other.size; j++) // nested loop of the rhs Poly
            {
                returnVal.coeffPtr[i + j] += this->coeffPtr[i] * other.coeffPtr[j]; //multiply Poly's by adding the power of lhs and rhs of the same index, and multiplying the coefficient
            }
        }
    }

    return returnVal; // return the answer
}

// ------------------------------------Mathematical operator +=-----------------------------------------------
// Description: Adds two Poly's, then assigns it to the lhs Poly
// ---------------------------------------------------------------------------------------------------

Poly& Poly::operator+=(const Poly& other)
{
    *this = *this + other; // A += B --> A = A + B
    return *this;
}

// ------------------------------------Mathematical operator -=-----------------------------------------------
// Description: Subtracts two Poly's, then assigns it to the lhs Poly
// ---------------------------------------------------------------------------------------------------

Poly& Poly::operator-=(const Poly& other)
{
    *this = *this - other; // A -= B --> A = A - B
    return *this;
}

// ------------------------------------Mathematical operator *=-----------------------------------------------
// Description: Multiplies two Poly's, then assigns it to the lhs Poly
// ---------------------------------------------------------------------------------------------------

Poly& Poly::operator*=(const Poly& other) 
{
    *this = *this * other; // A *= B --> A = A * B
    return *this; 
}

// ------------------------------------Mathematical operator ==-----------------------------------------------
// Description: Checks if two Poly's are the same, returns true if they are
// They dont have to be the same size, a Poly of size 9, can have Poly 5x^2, where the 8th Power is just 0
// ---------------------------------------------------------------------------------------------------

bool Poly::operator==(const Poly& other) const 
{
    if(this->size == other.size) // if lhs and rhs are the same size
    {
        for(int i = 0; i < this->size; i++)  // runs a loop of the size of the Poly's (they're the same)
        {
            if(coeffPtr[i] != other.coeffPtr[i]) // checks every index to see if they're different
            {
                return false; // if at anypoint they are, returns false
            }
        }
        return true; // if it breaks out of the loop, all the value are the same, so true
    }
    else // theyre diff sizes
    {
        if(this->size < other.size) // if rhs is bigger 
        {
            for(int i = 0; i < this->size; i++) // run a loop of rhs size
            {
                if(coeffPtr[i] != other.coeffPtr[i]) // checks every index to see if they're different
                {
                    return false;  // if at anypoint they are, returns false
                }
            }
        
            for (int j = this->size; j < other.size; j++) // now checks for the remainder of the values to be 0
            {
                if(other.coeffPtr != 0) // if they are not all 0, they do not match
                {
                    return false; // retuns false
                }
            }
        return true; // if it breaks out of the loop succesfully, retuns true
        }

        else // if lhs is bigger
        {
            for(int i = 0; i < this->size; i++) // run a loop of lhs size
            {
                if(coeffPtr[i] != other.coeffPtr[i]) // checks every index to see if they're different
                {
                    return false; // if at anypoint they are, returns false
                }
            }
        
            for (int j = this->size; j < other.size; j++) // now checks for the remainder of the values to be 0
            {
                if(coeffPtr != 0) // if they are not all 0, they do not match
                { 
                    return false; // retuns false
                }
            }
        return true; // if it breaks out of the loop succesfully, retuns true
        }
    }
    
}

// ------------------------------------Mathematical operator ==-----------------------------------------------
// Description: Checks if two Poly's are the different, returns true if they are, false if theyre are the same
// ---------------------------------------------------------------------------------------------------

bool Poly::operator!=(const Poly& other) const 
{
    return !(*this == other); // if this == ohter, returns false, if not return true
}

// ------------------------------------istream operator>> overload-----------------------------------------------
// Description: user inputs a set of values, 1st value is a first coefficient, and 2nd value is the power of taht coeff
// so on and so forth until they put -1 for coeff and -1 for pow, where the input terminates
// ---------------------------------------------------------------------------------------------------

istream& operator>>(istream& in, Poly& other)
{
    int coeff; // variables for coefficient
    int pow; // and power

    bool input = true; 

    while(input) // while input is true
    {
        in >> coeff >> pow; // first value entered is coeff and second is it's power

        if((coeff == -1) && (pow == -1)) // if the values are -1 and -1, loop exits
        {
            break;
        }
        other.setCoeff(coeff, pow); // sets the poly object that is being created with the user input
    }

    return in; // end
}

// ------------------------------------ostream operator<< overload-----------------------------------------------
// Description: Outputs the Poly array in a form of a Polynomial. If the coeff is 1, the ouput is just x^pow.
// If the pow is also 1, then the output is just x. If the coeff isnt 0, then the poly gets displayes, otherwise
// that specific poly is just 0
// ---------------------------------------------------------------------------------------------------

ostream& operator<<(ostream& out, Poly& other) 
{
    bool zero = true; // zero check

    for(int i = other.size -1; i >=0; i--) // goes backwards in the array because Poly is displayed from largerst to smallest
    {
        if(other.coeffPtr[i] != 0) // if the coeff isnt 0
        {
            zero = false; // zero isnt true
            out << " "; // first value is empty string for display cleanliness

            if(other.coeffPtr[i] > 0) // if the value is > 0, then puts a +, if not then the value already has a -
            {
                out << "+";
            }
 
            out << other.coeffPtr[i]; // out the actual coeff

            if(i != 0 && i != 1) // then if the power (represented by the index) isnt 0 or 1, 
            {
                out << "x^" << i; // x^pow
            }
            if(i == 1) // if its 1 
            {
                out <<"x"; 
            }
        }   
    }

    if(zero) // if zero is true then the curr Poly value is 0
    {
        return out << "0";
    }
    else 
    {
        return out; // EOF
    }
}