#ifndef MAP_H
#define MAP_H
#include "settings.h"
#include "utils.h"


class Map {
public:
    char screen_map[height-1][width];
    char tmap[height-1][width];
    Point offset = Point(0);
    int* load();
    void init();
    void clear();
    void fill();
};

#endif // MAP_H
