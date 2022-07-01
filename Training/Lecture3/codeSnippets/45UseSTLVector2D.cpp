#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Demo of vector

int main()
{

    int rows = 4;
    int cols = 5;
    vector<vector<int>> A(rows,vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A[i][j] = (i+1)*10+j;
        }
    }

    cout << "\nMatrix content:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << A[i][j] << "     ";
        }
        cout << endl;
    }


    return 0;
}