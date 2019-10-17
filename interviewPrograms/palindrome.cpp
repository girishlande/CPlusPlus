#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <set>

using namespace std;
//Given the string, check if it is a palindrome.

//__Example__

//* For `inputString = "aabaa"`, the output should be <br /> `checkPalindrome(inputString) = true`;
//* For `inputString = "abac"`, the output should be <br /> `checkPalindrome(inputString) = false`;
//* For `inputString = "a"`, the output should be <br /> `checkPalindrome(inputString) = true`.

bool checkPalindrome(const string& s) {
    for(int i=0;i<s.length()/2;i++) {
        if (s[i]!=s[s.length()-i-1])
            return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << checkPalindrome("nitin");

    return a.exec();
}
