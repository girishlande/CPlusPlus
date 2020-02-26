#include <chrono>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    int SIZE = 9999999;
    vector<int> vec;
    for (int i = 0; i < SIZE; i++) {
        vec.push_back(i);
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "\n\n vector Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();

    list<int> lis;
    for (int i = 0; i < SIZE; i++) {
        lis.push_back(i);
    }
    end = std::chrono::steady_clock::now();
    std::cout << "\n\n list Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    return 0;
}
