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

    int curRow = 1, maxRow = 1, prevValue, value;
    cin >> prevValue;

    while (cin >> value) {
        if (prevValue == value)
            curRow++;
        else
            curRow = 1;
        
        maxRow = max(maxRow, curRow);
        prevValue = value;
    }

    cout << maxRow;
}