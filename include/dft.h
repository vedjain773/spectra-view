#ifndef DFT_H
#define DFT_H

#include <vector>
#include "mathUtils.h"
using namespace std;

void subMean(vector<float> &data);
vector<cis> calcDFT(int start, int N, vector<float> data);
vector<float> calcMag(vector<cis> data_k);

#endif