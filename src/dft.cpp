#include <iostream>
#include <vector>
#include <cmath>
#include "mathUtils.h"
#include "dft.h"
using namespace std;

void subMean(vector<float> &data) {
    float mean;
    float sum = 0.0;

    for (float data_i: data) {
        sum += data_i;
    }

    mean = sum / data.size();
    cout << "Mean: " << mean << endl;

    for (int i = 0; i < data.size(); i++) {
        data[i] = data[i] - mean;
    }
}

vector<float> hannCoeffs(int N) {
    vector<float> windowed_coeffs;

    for (int i = 0; i < N; i++) {
        int n = i;
        double theta = (2 * M_PIf * n  / (N-1));

        double cosTerm = cos(theta);
        windowed_coeffs.push_back(0.5 * (1 - cosTerm));
    }

    return windowed_coeffs;
}

vector<float> hannWindow(vector<float> hannCoeffs, int start, vector<float> data) {
    vector<float> windowed_data;
    int N = hannCoeffs.size();

    for (int i = 0; i < N; i++) {
        double windowed_term = hannCoeffs[i] * data[start + i];
        windowed_data.push_back(windowed_term);
    }

    return windowed_data;
}

vector<cis> calcDFT(int N, vector<float> windowed_data) {
    vector<cis> data_k;

    for (int k = 0; k < N; k++) {
        cis x_k;
        x_k.real = 0.0;
        x_k.imag = 0.0;

        for (int n = 0; n < N; n++) {
            cis x_n;

            float theta = (-2 * M_PIf * n * k / N);
            float real = cos(theta);
            float imag = -sin(theta);

            x_n.real = real;
            x_n.imag = imag;

            x_n = sMult(windowed_data[n], x_n);

            x_k = Add(x_k, x_n);
        }

        data_k.push_back(x_k);
    }

    return data_k;
}

vector<float> calcMag(vector<cis> data_k) {
    vector<float> magnitudes;

    for (cis i_k: data_k) {
        magnitudes.push_back(mag(i_k));
    }

    return magnitudes;
}
