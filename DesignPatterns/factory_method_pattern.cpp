#include <QCoreApplication>
#include <qdebug.h>
#include <iostream>
#include <vector>
using namespace std;
class Toy {
public:
    virtual void MakeSound()=0;
    static Toy* MakeToy(int choice);
};

class DuckToy:public Toy {
public:
    void MakeSound() {
        qDebug() <<"Quack Quack";
    }
};

class CatToy:public Toy {
public:
    void MakeSound() {
        qDebug() <<"Mew Mew";
    }
};

class DogToy:public Toy {
public:
    void MakeSound() {
        qDebug() <<"Woff Woff";
    }
};

Toy* Toy::MakeToy(int choice) {
    Toy* toy = 0;
    switch(choice) {
    case 1: toy= new DuckToy; break;
    case 2: toy= new CatToy; break;
    case 3: toy= new DogToy; break;
    }
    return toy;
}

int main()
{
    vector<Toy*> toys;

    for(int i=0;i<13;i++) {
        toys.push_back(Toy::MakeToy(i%3+1));
    }
    qDebug() << "\n";

    for(int j=0;j<toys.size();++j) {
        toys[j]->MakeSound();
    }

}
