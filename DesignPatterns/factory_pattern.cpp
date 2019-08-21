#include <QCoreApplication>
#include <qdebug.h>

#include <president.h>
class Shape {
protected:
    static int totol;
    int id;
public:
    Shape() {
        id=totol++;
    }
    virtual void draw()=0;
};
int Shape::totol=0;

class Circle:public Shape{
public:
    void draw() {
        qDebug() << "Drawing Circle id:"<<id;
    }
};
class Square:public Shape {
public:
    void draw() {
        qDebug() << "Drawing Square id:" <<id;
    }
};
class Ellipse:public Shape {
public:
    void draw() {
        qDebug() << "Drawing Ellipse id:" <<id;
    }
};
class Rectangle:public Shape {
public :
    void draw() {
        qDebug() << "Drawing Rectangle id:" <<id;
    }
};

class Factory {
public:
    virtual Shape* createCurvedShape()=0;
    virtual Shape* createStraightShape()=0;
};

class SimpleShapeFactory:public Factory {
public:
    Shape* createCurvedShape() {
        return new Circle();
    }
    Shape* createStraightShape() {
        return new Square();
    }
};

class RobustShapeFactory : public Factory {
public:
    Shape* createCurvedShape() {
        return new Ellipse();
    }
    Shape* createStraightShape() {
        return new Rectangle();
    }
};



#define SIMPLE

int main()
{
#ifdef SIMPLE
    Factory* factory = new SimpleShapeFactory();
#else
    Factory* factory = new RobustShapeFactory();
#endif
     Shape* arr[3];
     arr[0] = factory->createCurvedShape();
     arr[1] = factory->createStraightShape();
     arr[2] = factory->createCurvedShape();

     for(int i=0;i<3;i++)  {
         arr[i]->draw();
     }

}
