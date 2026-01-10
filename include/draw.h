#ifndef DRAW_H
#define DRAW_H

#include <vector>
#include <sys/ioctl.h>
#include <unistd.h>
using namespace std;

void getTerminalSize(int &width, int &height);
void drawBars(vector<float> bands, int height);

#endif
