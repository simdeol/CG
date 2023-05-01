#include <iostream>
#include <graphics.h>
#include<cmath>
using namespace std;

// Hermite curve function
float hermite(float p0, float t0, float p1, float t1, float t) {
    float h1 = 2 * pow(t, 3) - 3 * pow(t, 2) + 1;
    float h2 = -2 * pow(t, 3) + 3 * pow(t, 2);
    float h3 = pow(t, 3) - 2 * pow(t, 2) + t;
    float h4 = pow(t, 3) - pow(t, 2);
    return h1 * p0 + h2 * p1 + h3 * t0 + h4 * t1;
}

// Bezier curve function
float bezier(float p0, float p1, float p2, float p3, float t) {
    float b1 = pow(1 - t, 3);
    float b2 = 3 * t * pow(1 - t, 2);
    float b3 = 3 * pow(t, 2) * (1 - t);
    float b4 = pow(t, 3);
    return b1 * p0 + b2 * p1 + b3 * p2 + b4 * p3;
}

int main() {
    // Initialize graphics window
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw Hermite curve
    setcolor(RED);
    float x1 = 100, y1 = 200, x2 = 400, y2 = 200, t1 = 1, t2 = 2;
    for (float t = 0; t <= 1; t += 0.01) {
        float x = hermite(x1, t1, x2, t2, t);
        float y = hermite(y1, t1, y2, t2, t);
        putpixel(x, y, RED);
    }

    // Draw Bezier curve
    setcolor(GREEN);
    float bx1 = 100, by1 = 400, bx2 = 200, by2 = 100, bx3 = 300, by3 = 500, bx4 = 400, by4 = 400;
    for (float t = 0; t <= 1; t += 0.01) {
        float x = bezier(bx1, bx2, bx3, bx4, t);
        float y = bezier(by1, by2, by3, by4, t);
        putpixel(x, y, GREEN);
    }

    // Close graphics window
    getch();
    closegraph();
    return 0;
}

