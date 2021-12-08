#include <QCoreApplication>
#include <qdebug.h>
#include <iostream>
#include <vector>
using namespace std;

class I {
public:
    virtual ~I() {

    }
    virtual void do_it()=0;
};

class A: public I {
public:
    ~A() {
        cout<< "\n A destructor";
    }
    void do_it() {
        cout << "\n A";
    }
};

class D: public I {
    I* m_wrapper{0};
public:
    D(I* ptr):m_wrapper(ptr) {}
    void do_it() {
        if (m_wrapper) {
            m_wrapper->do_it();
        }
    }
    ~D() {
        if (m_wrapper) {
            delete m_wrapper;
        }
    }
};

class X: public D {
public:
    X(I* core) :D(core) {

    }
    ~X() {
        cout << "\nX destructor";
    }
    void do_it() {
        D::do_it();
        cout << " X ";
    }
};

class Y: public D {
public:
    Y(I* core) :D(core) {

    }
    ~Y() {
        cout << "\nY destructor";
    }
    void do_it() {
        D::do_it();
        cout << " Y ";
    }
};

class Z: public D {
public:
    Z(I* core) :D(core) {

    }
    ~Z() {
        cout << "\nZ destructor";
    }
    void do_it() {
        D::do_it();
        cout << " Z ";
    }
};



int main()
{
    I* i1 = new A();
    i1->do_it();
    delete i1;

    I* i2 = new X(new Y(new Z(new A())));
    i2->do_it();
    delete i2;


    cout << "\n\n\n";
}
