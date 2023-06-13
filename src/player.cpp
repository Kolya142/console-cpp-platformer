#include "player.h"

Player::Player(int _x, int _y)
{
    x = _x;
    y = _y;
}

void Player::update(Map *map, int width, int height)
{
    if (GetKeyState('V') < 0) {noclip = !noclip; Sleep(10);}
    if (!noclip) {
        // if (GetKeyState('A') < 0 && map->screen_map[y][x-1] != '*' && x > 0) x -= 1;
        // if (GetKeyState('D') < 0 && map->screen_map[y][x+1] != '*') x += 1;
        if (GetKeyState('A') < 0 && map->screen_map[y][0] != '*') x -= 1;
        if (GetKeyState('D') < 0 && map->screen_map[y][2] != '*') x += 1;

        if (GetKeyState(VK_SPACE) < 0 &&
            !jump &&
            (y == height-1 || map->screen_map[y+1][1] == '*') &&
            map->screen_map[y-1][1] != '*'
            )  {
                jump = true;
                dy = y;
        }

        if (map->screen_map[y+1][1] == '*') y -= 1;

        // Make sure the player stays within the bounds of the map
        /*
        if (x < 0)
            x = 0;
        if (x >= width)
            x = width - 1;
        */
        if (y < height-1 && !jump)
            y += 1;
        if (y < 1) {y = 1; jump = false;}
        if (jump) {
            if (y <= dy - 5) jump = false;
            y -= 1;
        }
        if (map->screen_map[y][1] == '*') {y += 1; jump = false;}

    }
    else {
        if (GetKeyState('W') < 0) y -= 1;
        if (GetKeyState('A') < 0) x -= 1;
        if (GetKeyState('S') < 0) y += 1;
        if (GetKeyState('D') < 0) x += 1;
        /*
        if (x <= 0)
            x = 0;
        if (x >= width)
            x = width - 1;
        */
        if (y <= 0)
            y = 0;
        if (y >= height)
            y = height - 1;
    }
    // Modify the map to reflect the player's position
    map->offset.x = x+1;
    map->screen_map[y][1] = 'p';
}
