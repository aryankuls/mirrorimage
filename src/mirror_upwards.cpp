#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace mirror
{
    void mirror_up(char *buffer,int W, int H)
    {
        ofstream mirror_image{"../img/mirror_up.yuv"};
        
        // int c=0;
        for (int i = W * H - 1; i >= 0; i--)
        {
            // buffer_y[c] = buffer[i];
            mirror_image << buffer[i];
            // c++;
        }

        // c = 0;
        for (int i = 1.25 * W * H - 1; i >= W * H; i--)
        {
            // buffer_u[c] = buffer[i];
            mirror_image << buffer[i];
            // c++;
        }

        // c = 0;
        for (int i = 1.5 * W * H; i >= 1.25 * W * H; i--)
        {
            // buffer_v[c] = buffer[i];
            mirror_image << buffer[i];
            // c++;
        }
        mirror_image.close();
    }
}
