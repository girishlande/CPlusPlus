#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

char* getCharAtIndex(const char* input, int index)
{
    bool found = false;
    int total = 0;
    char* output = new char[3];
    output[2] = '\0';
    for (int i = 0; i < strlen(input); i+=2) {
        char ch = input[i];
        int freq = input[i + 1] - 48;
        total += freq;
        if (index < total) {
            output[0] = ch;
            output[1] = '\0';
            found = true;
            break;
        }
    }
    if (!found) {
        output[0] = '-';
        output[1] = '1';
    }
    return output;
}

int main()
{
    const char* str = "a1b1c4d5";
    int index = 7;
    char* output = getCharAtIndex(str, index-1);
    cout << string(output) << endl;

    return 0;
}
