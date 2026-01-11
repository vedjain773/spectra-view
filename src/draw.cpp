#include <iostream>
#include "draw.h"

using namespace std;

const char* blocks[] = {" ", "▁", "▂", "▃", "▄", "▅", "▆", "▇", "█"};

void getRGB(string &colStr, float ratio) {
    if (ratio > 0.66) {
        colStr = "\033[38;2;243;139;168m";
    } else if (ratio > 0.33) {
        colStr = "\033[38;2;249;226;175m";
    } else {
        colStr = "\033[38;2;137;180;250m";
    }
}

void getTerminalSize(int &width, int &height) {
    struct winsize w;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
        width = 80;
        height = 24;
    } else {
        width = w.ws_col;
        height = w.ws_row;
    }
}

void drawBars(vector<float> bands, int height) {
    int B = bands.size();

    vector<int> fullRows(B);
    vector<int> partial(B);

    for (int i = 0; i < B; i++) {
        float h = bands[i] * height;
        fullRows[i] = int(h);
        partial[i] = int((h - fullRows[i]) * 8);
    }

    std::string newFrame = "\033[H";

    for (int row = height; row > 0; row--) {
        float ratio = row / (float) height;
        string colStr = "";
        getRGB(colStr, ratio);

        newFrame += colStr;
        for (int i = 0; i < B; i++) {
            if (fullRows[i] >= row)
                newFrame += "██ ";
            else if (fullRows[i] == row - 1 && partial[i] > 0) {
                newFrame += blocks[partial[i]];
                newFrame += blocks[partial[i]];
                newFrame += " ";
            }
            else {
                newFrame += "   ";
            }
        }
        newFrame += "\n";
    }

    std::cout << newFrame << std::flush;
}
