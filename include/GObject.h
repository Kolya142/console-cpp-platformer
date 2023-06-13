#ifndef GOBJECT_H
#define GOBJECT_H
#include "Map.h"

class GObject
{
    public:
        GObject();

        int x;
        int y;
        void virtual update(Map *map, int width, int height);

    protected:

    private:
};

#endif // GOBJECT_H
