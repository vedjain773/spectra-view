#ifndef MATHUTILS_H
#define MATHUTILS_H

struct cis {
    float real;
    float imag;
};

cis Add(cis A, cis B);
cis sMult(float scalar, cis A);
float mag(cis A);

#endif