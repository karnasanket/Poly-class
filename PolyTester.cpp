#include "Poly.h"
#include <iostream>

using namespace std;

int main() {

    Poly A(5,7);
    cout << A << endl;

    A.setCoeff(6, 5);
    A.setCoeff(10,0);
    A.setCoeff(20,1);
    A.setCoeff(4,2);
    A.setCoeff(9,3);
    A.setCoeff(6,4);
    A.setCoeff(99,6);
    A.setCoeff(32,8);
    A.setCoeff(0,9);


    cout << A << endl;
    return 0;
}