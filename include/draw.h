#ifndef DRAW_H
#define DRAW_H

#include <vector>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string>
using namespace std;

void getRGB(int &r, int &g, int &b, float ratio);
void getTerminalSize(int &width, int &height);
void drawBars(vector<float> bands, int height);

#endif
