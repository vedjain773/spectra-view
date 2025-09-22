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

vector<cis> calcDFT(int start, int N, vector<float> data) {
    vector<cis> data_k;

    for (int k = 0; k < N; k++) {
        cis x_k;
        x_k.real = 0.0;
        x_k.imag = 0.0;

        for (int n = 0; n < N; n++) {
            cis x_n;

            float theta = (-2 * M_PIf * n * k / N);
            float real = cos(theta);
            float imag = sin(theta);

            x_n.real = real;
            x_n.imag = imag;

            x_n = sMult(data[start * N + n], x_n);

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