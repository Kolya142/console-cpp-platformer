#include "GObject.h"

GObject::GObject()
{
    // pass
}
void GObject::update(Map *map, int width, int height)
{
    int _x = x - map->offset.x;
    map->screen_map[y][_x] = '*';
}
