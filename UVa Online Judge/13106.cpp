#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int height, width;
    if (!(cin >> height >> width))
        return 0;

    vector<vector<int>> mine(height, vector<int>(width));
    for (vector<int> &row : mine)
        for (int &x : row)
            cin >> x;

    vector<int> row;
    for (int colIndex = 0; colIndex < width; colIndex++) {
        vector<int> col;
        for (int rowIndex = 0; rowIndex < height; rowIndex++) {
            if (rowIndex == 0)
                col.push_back(mine[rowIndex][colIndex]);
            else if (rowIndex == 1)
                col.push_back(max(col[rowIndex - 1], mine[rowIndex][colIndex]));
            else
                col.push_back(max(col[rowIndex - 1], col[rowIndex - 2] + mine[rowIndex][colIndex]));    
        }
        if (colIndex == 0)
            row.push_back(col.back());
        else if (colIndex == 1)
            row.push_back(max(row[colIndex - 1], col.back()));
        else
            row.push_back(max(row[colIndex - 1], row[colIndex - 2] + col.back()));
    }

    cout << row.back() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}