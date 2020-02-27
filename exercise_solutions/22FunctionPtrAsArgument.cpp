#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isLengthCorrect(string str)
{
    return str.length() == 3;
}

bool isLengthMatching(string str, int len)
{
    return str.length() == len;
}

int countStringswithLength(vector<string> vec, int n,bool (*f)(string,int)) {
    int count = 0;
    for (auto x : vec) {
        if (f(x, n)) {
            count++;
        }
    }
    return count;
}

int main()
{
    vector<string> vec;
    vec.push_back("girish");
    vec.push_back("aji");
    vec.push_back("nvk");
    vec.push_back("gpl");
    vec.push_back("suhas");

    int count = count_if(vec.begin(), vec.end(), isLengthCorrect);
    cout << "strings with length 3 are:" << count << endl;

    cout << "\nOwn checker:" << countStringswithLength(vec, 5, isLengthMatching) <<endl;
    return 0;
}
