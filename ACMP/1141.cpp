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

    int prevValue = 1e9, curRow = 0, maxRow = 0;

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        if (prevValue == value)
            curRow++;
        else
            curRow = 1;

        maxRow = max(maxRow, curRow);

        prevValue = value;
    }

    cout << maxRow;
}