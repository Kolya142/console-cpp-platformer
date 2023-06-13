#ifndef UTILS_H
#define UTILS_H
#include "settings.h"

class Point
{
    public:
        int x;
        int y;
        Point(int _x, int _y) {
            x = _x;
            y = _y;
        }
        Point(int _x) {
            x = _x;
            y = _x;
        }
        operator+=(Point other) {
            x += other.x;
            y += other.y;
        }
        operator+=(int other) {
            x += other;
            y += other;
        }
        operator-=(Point other) {
            x -= other.x;
            y -= other.y;
        }
        operator-=(int other) {
            x -= other;
            y -= other;
        }
        operator*=(Point other) {
            x += other.x;
            y += other.y;
        }
        operator*=(int other) {
            x *= other;
            y *= other;
        }
        operator/=(Point other) {
            x /= other.x;
            y /= other.y;
        }
        operator/=(int other) {
            x /= other;
            y /= other;
        }
        /*
        operator+(Point other) {
            Point ret;
            ret.x = x + other.x;
            ret.x = y + other.y;
            return ret;
        }
        operator+(int other) {
            Point ret;
            ret.x = x + other;
            ret.x = y + other;
            return ret;
        }
        operator-Point other) {
            Point ret;
            ret.x = x - other.x;
            ret.x = y - other.y;
            return ret;
        }
        operator-(int other) {
            Point ret;
            ret.x = x - other;
            ret.x = y - other;
            return ret;
        }
        operator*(Point other) {
            Point ret;
            ret.x = x * other.x;
            ret.x = y * other.y;
            return ret;
        }
        operator*(int other) {
            Point ret;
            ret.x = x * other;
            ret.x = y * other;
            return ret;
        }
        operator/Point other) {
            Point ret;
            ret.x = x / other.x;
            ret.x = y / other.y;
            return ret;
        }
        operator/(int other) {
            Point ret;
            ret.x = x / other;
            ret.x = y / other;
            return ret;
        }
        */
};

#endif // UTILS_H
