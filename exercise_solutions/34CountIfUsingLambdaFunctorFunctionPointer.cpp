#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class test {
public:
    bool operator()(string s)
    {
        return s.length() == 5;
    }
} testlength;

bool isLength4(string s)
{
    return s.length() == 4;
}

int main()
{
    vector<string> names = { "Girish", "Ajit", "Suhas", "Sameer" };

    size_t count = count_if(names.begin(), names.end(), [](auto x) {
        return x.length() == 6;
    });
    cout << "names with length 6 :" << count << endl;

    size_t c1 = count_if(names.begin(), names.end(), isLength4);
    cout << "names with length 4 :" << c1 << endl;

    size_t c2 = count_if(names.begin(), names.end(), testlength);
    cout << "names with length  5 :" << c2 << endl;

    return 0;
}
