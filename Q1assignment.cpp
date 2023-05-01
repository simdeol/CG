//Q.1
#include<iostream>
#include<graphics.h>
#include<cmath>

using namespace std;

bool isOdd(int thickness){
    if(thickness%2==0)
        return false;

    // else
    return true;
}

int thicknessup(int thickness){
    if(isOdd(thickness))
        return (thickness-1)/2;
    
    // else
    return (thickness/2);
}

int thicknessdown(int thickness){
    if(isOdd(thickness))
        return (thickness-1)/2;
    
    // else
    return (thickness/2)-1;
}

void bresenham(int x1, int y1, int x2, int y2, int thickness) {

    int thickness_up = thicknessup(thickness);
    int thickness_down = thicknessdown(thickness);


    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        // cout << "(" << x1 << ", " << y1 << ")\n";
        putpixel(x1,y1,WHITE);
        if (x1 == x2 && y1 == y2) break;
        int e2 = err * 2;
        if (e2 > -dy) {
            for(int j = (y1-thickness_down); j<=(y1+thickness_up);j++){
                putpixel(x1,j,WHITE);
            }
            err -= dy;
            x1 += sx;
            
            
        }
        if (e2 < dx) {
            for(int j = (x1-thickness_down); j<=(x1+thickness_up);j++){
                putpixel(j,y1,WHITE);
            }
            err += dx;
            y1 += sy;
            
        }
    }
}

void bresenham_dotted(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    int i=0;
    while (true) {
        // cout << "(" << x1 << ", " << y1 << ")\n";
        if(i%5==0)
            putpixel(x1,y1,WHITE);
        i++;
        if (x1 == x2 && y1 == y2) break;
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void bresenham_dashed(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    int i=0;
    while (true) {
        // cout << "(" << x1 << ", " << y1 << ")\n";
        if((i/10)%2==0)
            putpixel(x1,y1,WHITE);

        i++;
        if (x1 == x2 && y1 == y2) break;
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int main() {

	int gd=DETECT,gm;
	int i,j,k,t;

    // bresenham modified code here
    cout<<"Enter thickness of the line: "<<endl;
    cin>>t;
    
    initgraph(&gd,&gm,"");
	bresenham(0,0,500,600,t);
    bresenham_dotted(10,10,300,400);
    bresenham_dashed(100,200,200,500);
	getch();
	closegraph();
	return 0;
}
