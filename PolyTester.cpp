#include "Poly.h"
#include <iostream>

using namespace std;

int main() {

    Poly A(5,7);
    cout << "A before" << A << endl;

    A.setCoeff(6, 5);
    A.setCoeff(10,0);
    A.setCoeff(20,1);
    A.setCoeff(4,2);
    A.setCoeff(9,3);
    A.setCoeff(6,4);
    A.setCoeff(99,6);
    A.setCoeff(32,8);
    A.setCoeff(0,9);

    Poly B(7);
    Poly C(9,2);

    B.setCoeff(2,1);
    B.setCoeff(9,5);

    C.setCoeff(1,6);
    C.setCoeff(5,0);

    cout << "A after" << A << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;

    Poly D(A);
    A = C;
    
    cout << "D: " << D << endl;
    cout << "A assingment operator " << A << endl;
    A = D;

    cout << "A assingment operator again " << A << endl;

    bool result = (D == D);
    cout << "Checking operator== " << result << endl;

    Poly E(7,2);
    Poly F(5, 2);

    Poly G = E + F + B + C + A;

    cout << "Addition check, G: " << G << endl;

    Poly H = B - A;

    cout << "Testing subtraction, H: " << H << endl;

    Poly I = B * C;

    cout << "Testing multiplication, I: " << I << endl;

    Poly J(C);
    Poly L = B;
    B -= J;
    
    
    Poly K = L - C;
    cout << "Testing -= J: " << B << endl;
    cout << "Testing B - C " << K << endl;


    return 0;
}