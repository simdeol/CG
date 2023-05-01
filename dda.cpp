#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

// Define point struct
struct Point {
    int x, y;
};

// DDA algorithm for drawing a line
void DDA(Point p1, Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int steps = max(abs(dx), abs(dy));
    float xIncrement = dx / (float) steps;
    float yIncrement = dy / (float) steps;
    float x = p1.x;
    float y = p1.y;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    Point p1 = {100, 100};
    Point p2 = {300, 300};
    DDA(p1, p2);
    getch();
    closegraph();
    return 0;
}

