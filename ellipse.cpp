#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

void drawEllipse(int x0, int y0, int a, int b) {
    int x = 0, y = b;
    int a2 = a * a, b2 = b * b;
    int d = 4 * b2 * ((x + 1) * (x + 1)) + a2 * ((2 * y - 1) * (2 * y - 1)) - 4 * a2 * b2;
    while (a2 * (2 * y - 1) > 2 * b2 * (x + 1)) {
        putpixel(x0 + x, y0 + y, WHITE);
        putpixel(x0 - x, y0 + y, WHITE);
        putpixel(x0 + x, y0 - y, WHITE);
        putpixel(x0 - x, y0 - y, WHITE);
        if (d < 0) {
            x++;
            d += 4 * b2 * (2 * x + 3);
        } else {
            x++;
            y--;
            d += 4 * b2 * (2 * x + 3) + 4 * a2 * (-2 * y + 2);
        }
    }
    d = b2 * ((2 * x + 1) * (2 * x + 1)) + 4 * a2 * ((y + 1) * (y + 1)) - 4 * a2 * b2;
    while (y + 1) {
        putpixel(x0 + x, y0 + y, WHITE);
        putpixel(x0 - x, y0 + y, WHITE);
        putpixel(x0 + x, y0 - y, WHITE);
        putpixel(x0 - x, y0 - y, WHITE);
        if (d < 0) {
            x++;
            y--;
            d += 4 * b2 * (2 * x + 2) + 4 * a2 * (-2 * y + 3);
        } else {
            y--;
            d += 4 * a2 * (-2 * y + 3);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawEllipse(250, 250, 200, 100);
    getch();
    closegraph();
    return 0;
}

