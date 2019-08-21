#include <QCoreApplication>
#include <qdebug.h>

class Widget {
public:
    virtual void draw() =0;
};
class LinuxButton:public Widget{
public:
    void draw() {
        qDebug() << "Drawing Linux Button";
    }
};
class LinuxMenu:public Widget {
public:
    void draw() {
        qDebug() << "Drawing Linux Menu";
    }
};
class WindowButton:public Widget {
public:
    void draw() {
        qDebug() << "Drawing Window Button";
    }
};
class WindowMenu:public Widget {
public:
    void draw() {
        qDebug() <<"Drawing Window Menu";
    }
};

class Factory {
public:
    virtual Widget* createButton()=0;
    virtual Widget* createMenu()=0;
};
class LinuxFactory:public Factory {
public:
    Widget* createButton(){
        return new LinuxButton;
    }
    Widget* createMenu() {
        return new LinuxMenu;
    }
};
class WindowFactory:public Factory {
public:
    Widget* createButton() {
        return new WindowButton;
    }
    Widget* createMenu(){
        return new WindowMenu;
    }
};

//#define LINUX
int main()
{

#ifdef LINUX
    Factory* os = new LinuxFactory();
#else
    Factory* os = new WindowFactory();
#endif
    Widget* items[3];
    items[0]= os->createButton();
    items[1]= os->createMenu();
    items[2]= os->createButton();

    for(int i=0;i<3;i++ ){
        items[i]->draw();
    }
}
