#include <iostream>
#include "readWav.h"
using namespace std;

int main () {
    wavHeaders data = readFile("data/sample-3s.wav");
    printWaveHeaders(data);
    return 0;
}