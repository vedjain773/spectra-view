#include <iostream>
#include <vector>
#include "readWav.h"
#include "normalize.h"
#include "mathUtils.h"
#include "dft.h"

int main () {
    wavHeaders data = readFile("data/sin-2000-3.wav");
    // printWaveHeaders(data);
    vector<float> ndata = normalize(data);

    subMean(ndata);
    double windowSize = 512.0;

    vector<float> windowed_coeffs = hannCoeffs((int) windowSize);
    vector<float> windowed_data = hannWindow(windowed_coeffs, 0, ndata);

    vector<cis> dftPost = calcDFT((int) windowSize, windowed_data);
    vector<float> mags = calcMag(dftPost);

    for (int i = 0; i < windowSize / 2; i++) {
        double freq = 44100.0 * i / windowSize;
        std::cout << freq << ": " << mags[i] << "\n";
    }

    return 0;
}
