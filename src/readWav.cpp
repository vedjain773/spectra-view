#include <iostream>
#include <fstream>
#include <vector>
#include "readWav.h"
using namespace std;

string readChar(ifstream &file) {
    char str[4];
    file.read(str, sizeof(str));
    return str;
}

uint32_t read4Bytes(ifstream &file) {
    uint32_t num;
    file.read(reinterpret_cast<char*>(&num), sizeof(num));
    return num;
}

uint16_t read2Bytes(ifstream &file) {
    uint16_t num;
    file.read(reinterpret_cast<char*>(&num), sizeof(num));
    return num;
}

wavHeaders readFile(string filePath) {
    ifstream audioFile(filePath, ios::in | ios::out);

    if (!audioFile) {
        cerr << "No Audio file found\n";
    }

    wavHeaders waveHeader;
    vector<wavData> dataVector;

    waveHeader.chunkid = readChar(audioFile);
    waveHeader.chunkSize = read4Bytes(audioFile);
    waveHeader.format = readChar(audioFile);
    waveHeader.subChunk1Id = readChar(audioFile);
    waveHeader.subChunk1Size = read4Bytes(audioFile);
    waveHeader.audioFormat = read2Bytes(audioFile);
    waveHeader.numChannels = read2Bytes(audioFile);
    waveHeader.sampleRate = read4Bytes(audioFile);
    waveHeader.byteRate = read4Bytes(audioFile);
    waveHeader.blockAlign = read2Bytes(audioFile);
    waveHeader.bitsPerSample = read2Bytes(audioFile);
    waveHeader.subChunk2Id = readChar(audioFile);
    waveHeader.subChunk2Size = read4Bytes(audioFile);

    int noOfSamples = waveHeader.subChunk2Size / (waveHeader.numChannels * waveHeader.bitsPerSample / 8);

    if (waveHeader.bitsPerSample != 16) {
        std::cout << "Incompatible";
    }

    if (waveHeader.numChannels == 2) {
        for (int i = 0; i < noOfSamples; i++) {
            wavData wavdata;
            int16_t left;
            int16_t right;

            left = read2Bytes(audioFile);
            right = read2Bytes(audioFile);

            wavdata.mono = (left + right) / 2;

            dataVector.push_back(wavdata);
        }
    }

    if (waveHeader.numChannels == 1) {
        for (int i = 0; i < noOfSamples; i++) {
            wavData wavdata;
            int16_t mono;

            mono = read2Bytes(audioFile);

            wavdata.mono = mono;

            dataVector.push_back(wavdata);
        }
    }

    waveHeader.dataVector = dataVector;

    audioFile.close();

    return waveHeader;
}

void printWaveHeaders(wavHeaders waveHeader) {
    cout << "Chunk Id: " + waveHeader.chunkid << endl;
    cout << "Chunk Size: " << waveHeader.chunkSize << endl;
    cout << "Format: " + waveHeader.format<< endl;
    cout << "Subchunk 1 Id: " + waveHeader.subChunk1Id << endl;
    cout << "Subchunk Size: " << waveHeader.subChunk1Size << endl;
    cout << "Audio Format: " << waveHeader.audioFormat << endl;
    cout << "Number of Channels: " << waveHeader.numChannels << endl;
    cout << "Sample Rate: " << waveHeader.sampleRate << endl;
    cout << "Byte Rate: " << waveHeader.byteRate << endl;
    cout << "Block Align: " << waveHeader.blockAlign << endl;
    cout << "Bits Per Sample: " << waveHeader.bitsPerSample << endl;
    cout << "Subchunk 2 Id: " + waveHeader.subChunk2Id << endl;
    cout << "Subchunk 2 Size: " << waveHeader.subChunk2Size<< endl;
}
