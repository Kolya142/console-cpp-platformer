#ifndef BRICK_H
#define BRICK_H
#include "GObject.h"


class Brick : GObject
{
    public:
        int x,y,width,height;
        Brick(int _x, int _y, int _width, int _height);
        Brick();
        virtual void update(Map *map, int mwidth, int mheight);

    protected:

    private:
};

#endif // BRICK_H
