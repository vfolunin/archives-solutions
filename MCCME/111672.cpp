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
  
    int prevValue, type = 0, curRow = 1, maxRow = 1;
    cin >> prevValue;

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        if (type == -1 && prevValue < value || type == 1 && prevValue > value) {
            curRow++;
        } else if (prevValue != value) {
            type = prevValue < value ? -1 : 1;
            curRow = 2;
        } else {
            type = 0;
            curRow = 1;
        }

        prevValue = value;
        maxRow = max(maxRow, curRow);
    }

    cout << maxRow;
}