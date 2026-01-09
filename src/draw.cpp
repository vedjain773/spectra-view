#include <iostream>
#include "draw.h"

using namespace std;

const char* blocks[] = {" ", "▁", "▂", "▃", "▄", "▅", "▆", "▇", "█"};

void drawBars(vector<float> bands, int height) {
    int B = bands.size();

    vector<int> fullRows(B);
    vector<int> partial(B);

    for (int i = 0; i < B; i++) {
        float h = bands[i] * height;
        fullRows[i] = int(h);
        partial[i] = int((h - fullRows[i]) * 8);
    }

    // Clear screen, move cursor to top-left
    std::cout << "\033[H\033[J";

    for (int row = height; row > 0; row--) {
        for (int i = 0; i < B; i++) {
            if (fullRows[i] >= row)
                std::cout << "█";
            else if (fullRows[i] == row - 1 && partial[i] > 0)
                std::cout << blocks[partial[i]];
            else
                std::cout << " ";
        }
        std::cout << "\n";
    }
}
