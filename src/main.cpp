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
    printWaveHeaders(data);
    vector<float> ndata = normalize(data);

    subMean(ndata);

    vector<vector<float>> dftMags;

    for (int i = 0; i < 140; i++) {
        vector<cis> dftRes;
        dftRes = calcDFT(i, 1000, ndata);

        vector<float> mags;
        mags = calcMag(dftRes);

        dftMags.push_back(mags);
    }

    fstream freqCSV("data/freq.csv", ios::app | ios::out);
    
    for (int i = 0; i < 140; i++) {
        freqCSV << i << ",";
        
        for (int j = 0; j < 500; j++) {
            freqCSV << dftMags[i][j] << ",";
        }

        freqCSV << endl;
    }

    freqCSV.close();

    return 0;
}