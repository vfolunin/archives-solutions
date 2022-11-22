#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int curRow = 0, maxRow = 0;

    for (int i = 0; i < 30; i++) {
        int value;
        cin >> value;

        if (value < 0)
            curRow++;
        else
            curRow = 0;
        
        maxRow = max(maxRow, curRow);
    }

    cout << maxRow;
}