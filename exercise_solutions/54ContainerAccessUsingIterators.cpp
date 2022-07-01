#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

template<class T>
void display(T it, T end)
{
    while (it != end) {
        cout << *(it++) << endl;
    }
}

int main() {

    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);

    vector<string> v2;
    v2.push_back("Girish");
    v2.push_back("Ajit");
    v2.push_back("Suhas");

    vector<int>::iterator it = v1.begin();
    display(it,v1.end());

    display(v2.begin(), v2.end());

    return 0;
}

