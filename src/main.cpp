#include <iostream>
#include <vector>
#include "readWav.h"
#include "normalize.h"
#include "mathUtils.h"
#include "dft.h"
#include "draw.h"

#include <thread>
#include <chrono>

#define FMIN 50
#define FMAX 15000

int main () {
    int width = 0;
    int height = 0;

    getTerminalSize(width, height);

    const int NO_OF_BANDS = width / 3;

    wavHeaders data = readFile("data/sample-3s.wav");
    vector<float> ndata = normalize(data);

    int samples = ndata.size();

    subMean(ndata);
    double windowSize = 512.0;
    int hopsize = 256.0;

    vector<float> windowed_coeffs = hannCoeffs((int) windowSize);
    vector<int> be = bandEdges(FMIN, FMAX, NO_OF_BANDS);

    vector <vector <float>> frames;
    vector<float> prevFrame(windowSize, 0);

    std::cout << "Loading..." << "\n";

    for (int i = 0; i < samples; i += hopsize) {
        vector<float> windowed_data = hannWindow(windowed_coeffs, i, ndata);

        vector<cis> dftPost = calcDFT((int) windowSize, windowed_data);
        vector<float> mags = calcMag(dftPost);

        int bandCount = 0;
        int binCount = 0;

        vector<float> bands(NO_OF_BANDS, 0.0);

        while (bandCount < NO_OF_BANDS) {
            while (binCount < windowSize / 2) {
                double freq = 44100.0 * binCount / windowSize;
                if (freq < be[bandCount]) {
                    bands[bandCount] += mags[binCount];
                    binCount++;
                } else {
                    break;
                }
            }

            bandCount++;
        }

        frames.push_back(bands);
    }

    for (auto &bandFrames: frames) {
        processBands(bandFrames, prevFrame);
        drawBars(bandFrames, height);
        std::this_thread::sleep_for(std::chrono::milliseconds(6));  // ~30 FPS
    }

    return 0;
}
