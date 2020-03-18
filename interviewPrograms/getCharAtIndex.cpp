#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// write a program to get character at given index from decompressed string 
// e.g 
// input string: "a4b5c2d7"
// index: 7
// output: Character at index 7 is b
// input string: "a4b5c2d7"
// index: 12
// output: Character at index 12 is d
// write definition of following function 
char* getCharAtIndex(const char* input, int index);

int main()
{
    const char* str = "a4b5c2d7";
    int index = 12;
    char* output = getCharAtIndex(str, index - 1);
    cout << "Character at index " << index << " is " << string(output) << endl;

    return 0;
}

char* getCharAtIndex(const char* input, int index)
{
    bool found = false;
    int total = 0;
    char* output = new char[3];
    output[2] = '\0';
    for (int i = 0; i < strlen(input); i += 2) {
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
