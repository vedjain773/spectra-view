#include <iostream>
#include <vector>
#include <fstream>
#include "readWav.h"
#include "normalize.h"
#include "mathUtils.h"
#include "dft.h"
using namespace std;

int main () {
    wavHeaders data = readFile("data/sample-3s.wav");
    vector<float> ndata = normalize(data);

    vector<cis> dftRes;
    dftRes = calcDFT(1000, ndata);

    vector<float> mags;
    mags = calcMag(dftRes);

    int counter = 0;
    for (float mag: mags) {
        cout << counter << " " << mag << endl;
        counter = counter + 1;
    }

    fstream results("data/results.txt", ios::app | ios::out);

    for (int k = 0; k < 1000; k++) {
        results << (0.001 * k * 44100) << "  " << mags[k] << endl;
    }

    results.close();

    return 0;
}