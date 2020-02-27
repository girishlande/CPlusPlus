#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Animal {
public:
    Animal()
    {
        cout << "Animal constructor\n";
    }
    ~Animal()
    {
        cout << "Animal destructor\n";
    }
    virtual void makeNoise() = 0;
};

class Dog : public Animal {
public:
    Dog()
    {
        cout << "Dog constructor\n";
    }
    ~Dog()
    {
        cout << "Dog destructor\n";
    }
};

class Labrador : public Dog {
public:
    Labrador()
    {
        cout << "Labrador constructor\n";
    }
    ~Labrador() {
        cout << "Labrador destructor\n";
    }
    void makeNoise() {
        cout << "Labrador barking\n";
    }
};

int main()
{
    //Animal a1;
    //Dog d1;
    Labrador l1;
    Animal& a1 = l1;
    a1.makeNoise();

    return 0;
}
