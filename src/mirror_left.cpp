#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace mirror
{
    void mirror_left(char *buffer,char *buffer_y,char *buffer_u,char *buffer_v,int W,int H)
    {
        ofstream mirror_image{"../img/mirror_left.yuv"};
        cout << buffer[0];
        int c = 0;
        for (int i = 0; i < W * H; i++)
        {
            buffer_y[c] = buffer[i];
            c++;
        }

        c = 0;
        for (int i = W * H; i < 1.25 * W * H; i++)
        {
            buffer_u[c] = buffer[i];
            c++;
        }

        c = 0;
        for (int i = 1.25 * W * H; i < 1.5 * W * H; i++)
        {
            buffer_v[c] = buffer[i];
            c++;
        }
        int i,t=0;
        for (i = 1; i <= H; i++)
        {
            for (int j = i*W-1; j >= t; j--)
            {
                mirror_image << buffer_y[j];
            }
            t+=W;
        }

        t=0;
        for (i = 1; i <= H / 2; i++)
        {
            for (int j = i*W/2 - 1; j >= t; j--)
            {
                mirror_image << buffer_u[j];
            }
            t+=W/2;
        }

        t=0;
        for (i = 1; i <= H / 2 + 1; i++)
        {
            for (int j = i*W/2 -1; j >= t; j--)
            {
                mirror_image << buffer_v[j];
            }
            t+=W/2;
        }
        mirror_image.close();
    }
} 
