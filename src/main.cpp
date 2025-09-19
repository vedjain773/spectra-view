#include <iostream>
#include "readWav.h"
#include "normalize.h"
using namespace std;

int main () {
    wavHeaders data = readFile("data/sample-3s.wav");
    printWaveHeaders(data);
    normalize(data);
    return 0;
}