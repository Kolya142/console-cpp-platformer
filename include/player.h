#ifndef PLAYER_H
#define PLAYER_H
#include "Map.h"
#include "settings.h"
#include "GObject.h"
#include <stdio.h>
#include <Windows.h>

class Player : public GObject
{
    public:
        int dy = height-2;
        bool noclip = false;
        bool jump = false;
        Player(int _x, int _y);
        void update(Map *map, int width, int height);

    protected:

    private:

};

#endif // PLAYER_H
