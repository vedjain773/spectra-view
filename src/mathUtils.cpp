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

vector<int> bandEdges(int fmin, int fmax, int noOfBands) {
    vector<int> bandEdgeVec;
    double ratio = fmax / (double) fmin;

    for (int i = 0; i <= noOfBands; i++) {
        double power = i / (double) noOfBands;
        double exp = pow(ratio, power);

        int prod = floor(fmin * exp);
        bandEdgeVec.push_back(prod);
    }

    return bandEdgeVec;
}

void processBands(vector<float> &bands, vector<float> &prevBands, float alpha) {
    float sum = 0.0;

    for (int i = 0; i < bands.size(); i++) {
        bands[i] = alpha * prevBands[i] + (1 - alpha) * bands[i];
    }

    for (float &band: bands) {
        band = log10(1.01f + band);
    }

    for (float &band: bands) {
        sum += band;
    }

    for (float &band: bands) {
        band = band / sum;
    }

    prevBands = bands;
}
