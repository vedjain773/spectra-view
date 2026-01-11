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

void processBands(vector<float> &bands, vector<float> &prevBands) {
    float greatest = 0.0;
    float scale_factor = 2.0;

    for (int i = 0; i < bands.size(); i++) {
        float ratio = i / (float) bands.size();
        bands[i] = bands[i] * (1 + ratio * scale_factor);
    }

    for (int i = 0; i < bands.size(); i++) {
        if (bands[i] > prevBands[i]) {
            float alpha_rise = 0.1;
            bands[i] = alpha_rise * prevBands[i] + (1.0 - alpha_rise) * bands[i];
        } else {
            float alpha_fall = 0.5;
            bands[i] = alpha_fall * prevBands[i] + (1.0 - alpha_fall) * bands[i];
        }
    }

    for (float &band: bands) {
        band = log10(1.0f + band);
    }

    vector<float> gaussianBands = bands;

    for (int i = 0; i < bands.size(); i++) {
        float prev = 0.0f;
        float ahead = 0.0f;

        if (i != 0) {
            prev = bands[i-1];
        }

        if (i != bands.size() - 1) {
            ahead = bands[i+1];
        }

        gaussianBands[i] = (0.8 * bands[i] + 0.1 * prev + 0.1 * ahead);
    }

    bands = gaussianBands;

    for (float &band: bands) {
        if (band > greatest) {
            greatest = band;
        }
    }

    for (float &band: bands) {
        band = band / greatest;
    }

    prevBands = bands;
}
