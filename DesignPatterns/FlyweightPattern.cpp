#include <QCoreApplication>
#include <qdebug.h>
#include <iostream>
#include <vector>
using namespace std;

class Gazillion {
public :
    Gazillion(int v) {
        m_value = v;
        cout<< "\nconstructor:" << m_value ;
    }

    ~Gazillion() {
        cout<< "\ndestructor:" << m_value ;
    }

    void report(int value) {
        cout <<"  " << m_value << " " <<value;
    }
private:
    int m_value;
};

class Factory {
    static Gazillion *s_pool[];
public:
    static int X,Y;

    static Gazillion* getFly(int n) {
        if(!s_pool[n]) {
            s_pool[n] = new Gazillion(n);
        }
        return s_pool[n];
    }

    static void clean_up() {
        cout << "\n destructors:";
        for(int i=0;i<X;++i) {
            if (s_pool[i]) {
                delete s_pool[i];
            }
        }
    }
};

int Factory::X=6;
int Factory::Y=10;

Gazillion* Factory::s_pool[]={0,0,0,0,0,0};

int main()
{
    for(int i=0;i<Factory::X;i++) {
        for(int j=0;j<Factory::Y;++j) {
            Factory::getFly(i)->report(j);
        }
        cout<<"\n";
    }

    Factory::clean_up();
    cout << "\n\n\n";
}
