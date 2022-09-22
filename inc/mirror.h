#ifndef MIRROR_API_H
#define MIRROR_API_H


namespace mirror
{

void mirror_up(char *buffer,int W,int H);

void mirror_left( char *buffer, char *buffer_y, char *buffer_u, char *buffer_v,int W,int H);

}

#endif