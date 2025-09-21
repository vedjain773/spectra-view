#include <iostream>
#include <cmath>
#include "mathUtils.h"
using namespace std;

cis Add(cis A, cis B) {
    cis Sum;

    Sum.real = A.real + B.real;
    Sum.imag = A.imag + B.imag;

    return Sum;
}

cis sMult(float scalar, cis A) {
    cis sProd;

    sProd.real = scalar * A.real;
    sProd.imag = scalar * A.imag;

    return sProd;
}

float mag(cis A) {
    float magnitude;
    magnitude = sqrt(A.real * A.real + A.imag * A.imag);
    return magnitude;
}