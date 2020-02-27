#include <iostream>
using namespace std;

template <class T>
void print(T obj)
{
    cout << obj << " type:" << typeid(obj).name() << endl;
}

int main()
{
    string name("ajit Lande");
    char ch = 'a';

    print(10);
    print(3.14);
    print("girish");
    print(string("Ajit"));
    print(name);
    print(ch);

    cout << endl;

    return 0;
}
