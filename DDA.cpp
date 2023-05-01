#include<iostream>
#include<graphics.h>
#include<cmath>

using namespace std;
drawDDA(float x1, float y1,float x2, float y2)
{
	float dy=abs(y2-y1), dx=abs(x2-x1),step;
	float y=y1, x=x1, m=dy/dx, xinc, yinc;
	if(abs(dx)>abs(dy))
	{
		step=dx;
	}
	else
	{
		step=dy;
	}
	xinc = dx / (float) step;
   	yinc = dy / (float) step;
	for(float i=0; i<=step; i++)
	{
		putpixel(round(x),round(y),YELLOW);
		y+=yinc;
		x+=xinc;
	}
	getch();
}
int main()
{
	float x1,x2,y1,y2;
	int gd=DETECT, gm;
	initgraph(&gd,&gm,"");
	cout<<"Enter the starting x coordinate for the line"<<endl;
	cin>>x1;
	cout<<"Enter the starting y coordinate for the line"<<endl;
	cin>>y1;
	cout<<"Enter the ending x coordinate for the line"<<endl;
	cin>>x2;
	cout<<"Enter the ending y coordinate for the line"<<endl;
	cin>>y2;
	drawDDA(x1,y1,x2,y2);
	closegraph();	
}
