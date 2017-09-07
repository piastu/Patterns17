#ifndef ROOM_H
#define ROOM_H


class room
{

public:
    room(int h, int w, int s);
    int getH();
    int getW();
    int getS();
private:
    int height;
    int width;
    int step;
};

#endif // ROOM_H
