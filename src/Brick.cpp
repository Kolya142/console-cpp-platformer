#include "Brick.h"

Brick::Brick(int _x, int _y, int _width, int _height)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
}
Brick::Brick()
{
    x = 0;
    y = 0;
    width = -1;
    height = -1;
}
void Brick::update(Map *map, int mwidth, int mheight)
{
    int _x = x - map->offset.x;
    map->screen_map[y][_x] = '*';
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            Point p = Point(i+x-map->offset.x, j+y);
            if ((p.x >= 0) && (p.y >= 0) && (p.x < mwidth) && (p.y < mheight))
                map->screen_map[p.y][p.x] = '*';
        }
    }
}
