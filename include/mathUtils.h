#ifndef MATHUTILS_H
#define MATHUTILS_H

#include <vector>
using namespace std;

struct cis {
    float real;
    float imag;
};

cis Add(cis A, cis B);
cis sMult(float scalar, cis A);
float mag(cis A);

vector<int> bandEdges(int fmin, int fmax, int noOfBands);
void processBands(vector<float> &bands, vector<float> &prevBands);

#endif
