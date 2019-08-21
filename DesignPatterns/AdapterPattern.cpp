#include <QCoreApplication>
#include <qdebug.h>
#include <iostream>
#include <vector>
using namespace std;

class Rectangle {

public:
    virtual void draw()=0;
};

class LegacyRectangle {
    int x1,y1,x2,y2;
public:
    LegacyRectangle(int x,int y,int z,int w):x1(x),y1(y),x2(z),y2(w) {
        cout << "\n Legacy rectangle constructor called !";
    }
    void olddraw() {
        cout << "\n Legacy rectangle old draw called!";
    }
};

class RectangleAdapter:public Rectangle,private LegacyRectangle {
public:
    RectangleAdapter(int x1,int y1,int x2,int y2):LegacyRectangle(x1,y1,x2,y2) {
        cout << "\n Rectangle adapter constructor called!";
    }
    void draw() {
        cout << "\n rectangle adapter draw() called!";
        LegacyRectangle::olddraw();
    }
};

int main()
{
    Rectangle* r1 = new RectangleAdapter(10,10,20,20);
    r1->draw();

}
