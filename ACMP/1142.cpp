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

    int prevValue = 0, curType = 0, curRow = 0, maxRow = 0;

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        if (!prevValue || prevValue == value) {
            curType = 0;
            curRow = 1;
        } else if (prevValue < value) {
            if (curType == 1) {
                curRow++;
            } else {
                curType = 1;
                curRow = 2;
            }
        } else {
            if (curType == 2) {
                curRow++;
            } else {
                curType = 2;
                curRow = 2;
            }
        }

        maxRow = max(maxRow, curRow);

        prevValue = value;
    }

    cout << maxRow;
}