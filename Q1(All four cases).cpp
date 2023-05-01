#include <graphics.h>
#include <iostream>

using namespace std;

void drawLine(int x1, int y1, int x2, int y2) {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Calculate slope
    float m = (float)(y2 - y1) / (float)(x2 - x1);

    // Determine which case applies
    int dx, dy, p, x, y;
    if (m >= 0 && m <= 1) {
        dx = x2 - x1;
        dy = y2 - y1;
        p = 2 * dy - dx;
        x = x1;
        y = y1;
        putpixel(x, y, WHITE);
        while (x < x2) {
            x++;
            if (p < 0) {
                p += 2 * dy;
            } else {
                y++;
                p += 2 * (dy - dx);
            }
            putpixel(x, y, WHITE);
        }
    } else if (m > 1) {
        dx = x2 - x1;
        dy = y2 - y1;
        p = 2 * dx - dy;
        x = x1;
        y = y1;
        putpixel(x, y, WHITE);
        while (y < y2) {
            y++;
            if (p < 0) {
                p += 2 * dx;
            } else {
                x++;
                p += 2 * (dx - dy);
            }
            putpixel(x, y, WHITE);
        }
    } else if (m < 0 && m >= -1) {
        dx = x2 - x1;
        dy = y1 - y2;
        p = 2 * dy - dx;
        x = x1;
        y = y1;
        putpixel(x, y, WHITE);
        while (x < x2) {
            x++;
            if (p < 0) {
                p += 2 * dy;
            } else {
                y--;
                p += 2 * (dy - dx);
            }
            putpixel(x, y, WHITE);
        }
    }
}
int main()
{
	int x1,x2,y1,y2;
cout<<" Bresenham's Line Drawing Algorithm \n\n";
cout<<" Enter the x co-ordinate of point 1: ";
cin>>x1;
cout<<"\n Enter the y co-ordinate of point 1: ";
cin>>y1;
cout<<"\n Enter the x co-ordinate of point 2: ";
cin>>x2;
cout<<"\nEnter the y co-ordinate of point 2: ";
cin>>y2;
cleardevice();

drawLine(x1,y1,x2,y2);
getch();
closegraph();
return 0;
}
       

