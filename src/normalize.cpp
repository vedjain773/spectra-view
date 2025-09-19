#include <iostream>
#include <vector>
#include "readWav.h"
#include "normalize.h"
using namespace std;

vector<float> normalize(wavHeaders wavheader) {
    vector<wavData> monoData = wavheader.dataVector;
    vector<float> normalizedSamples;
    float denom = 32768.0;
    float maxVal = 0.0;

    for (wavData data : monoData) {
        float nsample = data.mono / denom;
        normalizedSamples.push_back(nsample);

        maxVal = (nsample > maxVal) ? nsample : maxVal;
        // cout << "Normalized: " << nsample << endl;
    }

    cout << "Maximum Value: " << maxVal;
    return normalizedSamples;
}