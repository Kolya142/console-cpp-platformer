#include "Map.h"
#include "iostream"
#include <cstring>
#include <fstream>

void Map::init() {
    screen_map[height][width] = '\0';
}
void Map::fill() {
    for (int row = 0; row < height-1; row++) {
        for (int col = 0; col < width; col++) {
            screen_map[row][col] = tmap[row][col];
        }
    }
}
void Map::clear() {
    for (int i = 0; i < width; i++) {
        screen_map[0][i] = '.';
    }
    for (int i = 0; i < height; i++) {
        strncpy(screen_map[i], screen_map[0], width);
    }
}
int* Map::load() {
    std::fstream fs{"level.g2"};
    char c;
    int y = 0;
    int x = 0;
    fs >> std::noskipws >> c;
    static int p[2];

    while (fs >> std::noskipws >> c)
    {
        if (x >= width) {
            y += 1;
            x = 0;
        }
        if (c == 'p') {
            p[0] = x;
            p[1] = y;
            c = '.';
        }
        tmap[y][x] = c;
        x += 1;
    }
    return p;
}
