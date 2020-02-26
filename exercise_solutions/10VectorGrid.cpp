#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> grid(5);
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < 4; j++) {
            grid[i].push_back(i*grid.size()+j);
        }
    }

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << "  ";
        }
        cout << endl;
    }
    
    return 0;
}
