/* 4) Write a program to clip a polygon using Sutherland Hodgeman algorithm. */

#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std ;

class PolygonClipping {
	private:
		double xmin, xmax, ymin, ymax ; // coordinates for clipping window
		int *inVertex ; 		        // coordinates for line
		double *outVertex ;
		int *temp ;
		double m ;
		int sides, pointer ;
	public:
		PolygonClipping() ;
		~PolygonClipping() ;
		
		void input() ;
		void polygonClip() ;
		void leftClipping(double x1, double y1, double x2, double y2) ;
		void rightClipping(double x1, double y1, double x2, double y2) ;
		void bottomClipping(double x1, double y1, double x2, double y2) ;
		void topClipping(double x1, double y1, double x2, double y2) ;
};

PolygonClipping :: PolygonClipping() {
	xmin = 0 ;
	xmax = 40 ;
	ymin = 0 ;
	ymax = 40 ;
	sides = 0 ;
	inVertex = 0 ;
	outVertex = 0 ;
	temp = 0 ;
	pointer = 0 ;
	m = 0 ;
}

PolygonClipping :: ~PolygonClipping() {}

void PolygonClipping :: input() {
	cout << "\t\t\t\t\t\tEnter Coordinates of clipping window\n\n" ;
	cout << "Enter xmin-coordinate:  " ;
	cin >> xmin ;
	cout << "Enter ymin-coordinate:  " ;
	cin >> ymin ;
	cout << "\nEnter xmax-coordinate:  " ;
	cin >> xmax ;
	cout << "Enter ymax-coordinate:  " ;
	cin >> ymax ;
	
	cout << "\n\nEnter number of sides of polygon : " ;
	cin >> sides ;
	
	inVertex = new int[2*sides + 2] ;
	outVertex = new double[4*sides + 4] ;
	temp = new int[2*sides + 2] ;
	
	cout << "\n\n\t\t\t\t\t\tEnter Coordinates of line\n\n" ;
	
	int i=0 ;
	for(i=0 ; i<2*sides ; i=i+2) {
		cout << "\nEnter x-coordinate:  " ;
		cin >> inVertex[i] ;
		cout << "Enter y-coordinate:  " ;
		cin >> inVertex[i + 1] ;	
	}
	
	inVertex[2*sides] = inVertex[0] ;
	inVertex[2*sides+1] = inVertex[1] ;
	
	for(int i=0; i<2*sides + 2 ; i++) {
		temp[i] = round(inVertex[i]);
	}
	
	return ;
}

void PolygonClipping :: polygonClip() {
	int gd = DETECT, gm ;
	char pathtodriver[] = "";
	initgraph(&gd, &gm, pathtodriver) ;	
	
	rectangle(xmin,ymax,xmax,ymin);
    cout << "\n\t\t\t\t\t\tPolygon before Clipping" << endl ;
    drawpoly(sides, inVertex) ;
	line(inVertex[2*sides], inVertex[2*sides + 1] , inVertex[2*sides-2], inVertex[2*sides -1]);
	
	getch();
    cleardevice();
    
	int i = 0 ;
	
    for(i=0 ; i<2*sides ; i+=2) {
    	leftClipping(inVertex[i], inVertex[i+1], inVertex[i+2], inVertex[i+3]);
    }
    
    sides = pointer/2;
    
    for(i = 0 ; i<pointer ; i++)
		inVertex[i] = outVertex[i];
		
    inVertex[i] = inVertex[0] ;
    inVertex[i+1] = inVertex[1];
    
	pointer=0;
    
	for(i=0 ; i<2*sides ; i+=2)
		topClipping(inVertex[i], inVertex[i+1], inVertex[i+2] , inVertex[i+3]);
    
	sides = pointer/2;
	
    for(i=0;i < pointer;i++)
		inVertex[i] = outVertex[i] ;
    
	inVertex[i] = inVertex[0] ;
    inVertex[i+1] = inVertex[1] ;
    
	pointer=0;
    
	for(i=0 ; i<2*sides ; i+=2)
		rightClipping(inVertex[i], inVertex[i+1], inVertex[i+2], inVertex[i+3]) ;
    
	sides = pointer/2;
	
    for(i=0 ; i<pointer;i++)
		inVertex[i] = outVertex[i] ;
    
	inVertex[i] = inVertex[0];
    inVertex[i+1] = inVertex[1];
    
	pointer=0;
    
	for(i=0 ; i<2*sides ; i+=2)
		bottomClipping(inVertex[i],inVertex[i+1], inVertex[i+2], inVertex[i+3]);
    
	for(i=0 ; i<pointer ; i++)
		temp[i] = round(outVertex[i]);
		
	if(pointer)
		drawpoly(pointer/2 , temp);
	
	rectangle(xmin,ymax,xmax,ymin);
    cout << "\n\n\t\t\t\t\t\tPolygon after clipping";
    
	getch();
    closegraph();
		
	return ;
}

void PolygonClipping :: leftClipping(double x1, double y1, double x2, double y2) {
	if(x2 - x1) {
		m = (y2 - y1) / (x2 - x1) ;
	}else {
		m = INT_MAX ;
	}
	
	if(x1 >= xmin && x2 >= xmin) {
		outVertex[pointer] = x2 ;
		outVertex[pointer + 1] = y2 ;
		pointer += 2;
	}
	
	if(x1 < xmin && x2 >= xmin) {
		outVertex[pointer] = xmin ;
		outVertex[pointer + 1] = y1 + m*(xmin - x1) ;
		outVertex[pointer + 2] = x2 ;
		outVertex[pointer + 3] = y2 ;
		pointer +=4 ;
	}
	
	if(x1 >= xmin && x2 < xmin) {
		outVertex[pointer] = xmin ;
		outVertex[pointer + 1] = y1 + m*(xmin - x1) ;
		pointer +=2 ;
	}
}

void PolygonClipping :: topClipping(double x1, double y1, double x2, double y2) {
	if(y2 - y1) {
		m = (x2 - x1) / (y2 - y1) ;
	}else {
		m = INT_MAX ;
	}
	
	if(y1 <= ymax && y2 <= ymax) {
		outVertex[pointer] = x2 ;
		outVertex[pointer + 1] = y2 ;
		pointer += 2;
	}
	
	if(y1 > ymax && y2 <= ymax) {
		outVertex[pointer] = x1 + m*(ymax - y1);
		outVertex[pointer + 1] = ymax ;
		outVertex[pointer + 2] = x2 ;
		outVertex[pointer + 3] = y2 ;
		pointer +=4 ;
	}
	
	if(y1 <= ymax && y2 > ymax) {
		outVertex[pointer] = x1 + m*(ymax - y1) ;
		outVertex[pointer + 1] = ymax ;
		pointer +=2 ;
	}
}

void PolygonClipping :: rightClipping(double x1, double y1, double x2, double y2) {
	if(x2 - x1) {
		m = (y2 - y1) / (x2 - x1) ;
	}else {
		m = INT_MAX ;
	}
	
	if(x1 <= xmax && x2 <= xmax) {
		outVertex[pointer] = x2 ;
		outVertex[pointer + 1] = y2 ;
		pointer += 2;
	}
	
	if(x1 > xmax && x2 <= xmax) {
		outVertex[pointer] = xmax ;
		outVertex[pointer + 1] = y1 + m*(xmax - x1) ;
		outVertex[pointer + 2] = x2 ;
		outVertex[pointer + 3] = y2 ;
		pointer +=4 ;
	}
	
	if(x1 < xmax && x2 > xmax) {
		outVertex[pointer] = xmax ;
		outVertex[pointer + 1] = y1 + m*(xmax - x1) ;
		pointer +=2 ;
	}
}

void PolygonClipping :: bottomClipping(double x1, double y1, double x2, double y2) {
	if(y2 - y1) {
		m = (x2 - x1) / (y2 - y1) ;
	}else {
		m = INT_MAX ;
	}
	
	if(y1 >= ymin && y2 >= ymin) {
		outVertex[pointer] = x2 ;
		outVertex[pointer + 1] = y2 ;
		pointer += 2;
	}
	
	if(y1 < ymin && y2 >= ymin) {
		outVertex[pointer] = x1 + m*(ymin - y1) ;
		outVertex[pointer + 1] = ymin ;
		outVertex[pointer + 2] = x2 ;
		outVertex[pointer + 3] = y2 ;
		pointer +=4 ;
	}
	
	if(y1 >= ymin && y2 < ymin) {
		outVertex[pointer] = x1 + m*(ymin - y1) ;
		outVertex[pointer + 1] = ymin ;
		pointer +=2 ;
	}
}

int main() {
	PolygonClipping obj ;
	obj.input() ;
	obj.polygonClip() ;
	return 0 ;
}
