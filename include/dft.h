#ifndef DFT_H
#define DFT_H

#include <vector>
#include "mathUtils.h"
using namespace std;

void subMean(vector<float> &data);
vector<float> hannCoeffs(int N);
vector<float> hannWindow(vector<float> hannCoeffs, int start, vector<float> data);
vector<cis> calcDFT(int N, vector<float> windowed_data);
vector<float> calcMag(vector<cis> data_k);

#endif
