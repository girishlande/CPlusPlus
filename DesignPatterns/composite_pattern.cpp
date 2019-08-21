#include <QCoreApplication>
#include <qdebug.h>
#include <iostream>
#include <vector>
using namespace std;

class Component {
public:
    virtual void traverse()=0;
};

class Leaf:public Component {
    int m_value;
public:
    Leaf(int v):m_value(v) {}
    void traverse() {
        cout << " " << m_value;
    }
};

class Composite:public Component {
    vector<Component*> m_components;
public:
    Composite() {

    }
    void add(Component* c) {
        m_components.push_back(c);
    }
    void traverse() {
        for(int i=0;i<m_components.size();++i) {
            m_components[i]->traverse();
        }
    }
};


int main()
{
    Composite container[4];
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;++j) {
            container[i].add(new Leaf(i*3+j));
        }
    }

    for(int i=1;i<4;++i) {
        container[0].add(&(container[i]));
    }

    for(int i=0;i<4;++i) {
        container[i].traverse();
        cout << "\n";
    }


}
