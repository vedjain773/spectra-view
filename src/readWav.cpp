#include <iostream>
#include <fstream>
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