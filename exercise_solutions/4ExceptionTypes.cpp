#include <exception>
#include <iostream>

using namespace std;

void doProcessing()
{
    int level = 2;
    switch (level) {
    case 1:
        throw 8;
        break;
    case 2:
        throw string("string exception");
        break;
    case 3:
        throw 'z';
        break;
    default:
        throw 11;
        break;
    }
}

int main()
{
    try {
        doProcessing();
    } catch (int code) {
        cout << "exception caught:" << code << endl;
    } catch (string code) {
        cout << "exception caught:" << code << endl;
    } catch (char code) {
        cout << "exception caught:" << code << endl;
    } 

    cout << "program Finished execution\n\n";
    return 0;
}
