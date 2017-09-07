#include "room.h"

room::room(int h, int w, int s)
{
    height=h;
    width=w;
    step=s;
}

int room::getH()
{
    return height;
}

int room::getW()
{
    return width;
}

int room::getS()
{
    return step;
}

