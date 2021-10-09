#include<graphics.h>
#include <math.h>
#include <iostream>
#include <vector>
typedef struct PPoint {
	int x;
	int y;
};

void myLine(int x1,int y1,int x2,int y2) {
float dx=abs(x2-x1);
float dy=abs(y2-y1);
 float step=1;
 float x,y;
 int i;
 
if(dx>=dy)
step=dx;
else
step=dy;
 
dx=dx/step;
dy=dy/step;
 
x=x1;
y=y1;
 
i=1;
while(i<=step)
{
putpixel(x,y,5);
x=x+dx;
y=y+dy;
i=i+1;
delay(10);
}	
}

void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc+x, yc+y, RED);
    putpixel(xc-x, yc+y, RED);
    putpixel(xc+x, yc-y, RED);
    putpixel(xc-x, yc-y, RED);
    putpixel(xc+y, yc+x, RED);
    putpixel(xc-y, yc+x, RED);
    putpixel(xc+y, yc-x, RED);
    putpixel(xc-y, yc-x, RED);
}
 
// Function for circle-generation
// using Bresenham's algorithm
void circleBres(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x)
    {
        // for each pixel we will
        // draw all eight pixels
         
        x++;
 
        // check for decision parameter
        // and correspondingly
        // update d, x, y
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(xc, yc, x, y);
        delay(50);
    }
}

void gCircle(int cx, int cy, int r) {
	
	float sx = 0;
	float sy = 0;
	int startAngle = 30;
	for(int i=0;i<360;i++) {
	  float px = cx + r * cos(i*0.0174533);
      float py = cy + r * sin(i*0.0174533);	
      putpixel(px,py,RED);
      //delay(10);
      if (i==startAngle) {
      	sx = px;
      	sy = py;
      	moveto(sx,sy);
	  } else if(i==(startAngle+120) || i==(startAngle+240)) {
	  	lineto(px,py);
	  }
	}
	lineto(sx,sy);
}

void recursiveRect(std::vector<PPoint>& points,int depth) {
	std::vector<PPoint> newPoints;
   PPoint p1 = points[0];
   moveto(p1.x,p1.y);
   for(int i=1;i<5;i++) {
   	 PPoint p2 = points[i];
   	 lineto(p2.x,p2.y);
   	 int midx = (p1.x+p2.x)/2;
   	 int midy = (p1.y+p2.y)/2;
   	 newPoints.push_back(PPoint({midx,midy}));
   	 p1 = p2;
   }
   
   if(depth>1) {
   	  newPoints.push_back(newPoints[0]);
   	  recursiveRect(newPoints,depth-1);
   }	
}

void gRect(int x1,int y1,int x2,int y2) {
	std::vector<PPoint> points;
	points.push_back(PPoint{x1,y1});
	points.push_back(PPoint{x2,y1});
	points.push_back(PPoint{x2,y2});
	points.push_back(PPoint{x1,y2});
	points.push_back(PPoint{x1,y1});
	recursiveRect(points,3);
}

int main() {
	initwindow(600,600);
	
	
	setcolor(2);
	//setlinestyle(2,2,4);
	//myLine(100,100,200,200);
	
	//circleBres(300,300,100);
	gCircle(300,300,100);
	circle(300,300,50);
	
	gRect(100,100,250,200);
	
	getch();
}
