#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../inc/mirror.h"

using namespace std;

int main()
{
    int W = 1280, H = 720;
    ifstream image{"hk_yuv420.yuv", ios::binary};
    char buffer[int(1.5 * W * H) + 1]; //[(W * H + 1 / 4 * W * H + 1 / 4 * W * H) + 1];
    char buffer_y[W * H + 1];
    char buffer_u[int(0.25 * W * H) + 1];
    char buffer_v[int(0.25 * W * H) + 1];
    image.seekg(0);
    image.read(buffer, 1.5 * W * H + 1);
    mirror::mirror_left(buffer,buffer_y,buffer_u,buffer_v,W,H);
    mirror::mirror_up(buffer,W,H);
    image.close();
}