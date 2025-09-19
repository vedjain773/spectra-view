#ifndef READWAV_H
#define READWAV_H
using namespace std;

#include <fstream>

struct wavHeaders {
    string chunkid;
    uint32_t chunkSize;
    string format;
    string subChunk1Id;
    uint32_t subChunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    string subChunk2Id;
    uint32_t subChunk2Size;
};

string readChar(ifstream &file);
uint16_t read2Bytes(ifstream &file);
uint32_t read4Bytes(ifstream &file);
wavHeaders readFile(string filePath);
void printWaveHeaders(wavHeaders waveheader);

#endif