#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "player.h"
#include "GObject.h"
#include "settings.h"
#include "Brick.h"
#include "Map.h"
#include <chrono>
#define abs(x) (x < 0) ? -x : x

float getCurrentTimeInMilliseconds() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto duration = currentTime.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}


void setConsoleSize() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set the console screen buffer size
    COORD bufferSize = { width-1, height-1};
    SetConsoleScreenBufferSize(consoleHandle, bufferSize);

    // Set the console window size and position
    SMALL_RECT windowSize = { 0, 0, width-1,height-1};
    SetConsoleWindowInfo(consoleHandle, TRUE, &windowSize);
}

// Function to set the cursor position in the console
void setCursor(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
}
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;  // Set the cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
Map map = Map();
void draw(bool frist) {
    setCursor(0, 0);
    for (int row = 0; row < height-1; row++) {
        for (int col = 0; col < width; col++) {
            // if (map.screen_map[row][col] == '.') continue;
            setCursor(col,  row);
            std::cout << map.screen_map[row][col];
        }
        if (frist) Sleep(10);
    }
}

int main()
{
    setConsoleSize();
    map.init();
    // int* p = map.load();
    hideCursor();
    Player player = Player(1, 1);
    Brick bricks[5];
    bricks[0] = Brick(45, 16, 40, 4);
    bricks[1] = Brick(60, 12, 5, 4);
    bricks[2] = Brick(93, 16, 40, 4);
    std::string black = "";
    for (int i = 0; i < width; i ++) black += " ";
    bool frist = true;
    float fps = 0.0f;
    while (GetKeyState(VK_ESCAPE) >= 0) {
        float st = getCurrentTimeInMilliseconds();
        map.clear();
        for (int i = 0; i < 3; i++)
            bricks[i].update(&map, width, height-1);
        player.update(&map, width, height-1);
        draw(frist);
        setCursor(0, height-1);
        std::cout << black;
        setCursor(0, height-1);
        std::cout << "fps: ~" << fps;
        if (frist) frist = !frist;
        fps = abs(100000 / (getCurrentTimeInMilliseconds() - st));
    }
    return 0;
}
