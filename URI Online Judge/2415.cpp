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

    int valCount, prevVal;
    cin >> valCount >> prevVal;

    int curRow = 1, maxRow = 1;
    for (int i = 1; i < valCount; i++) {
        int curVal;
        cin >> curVal;

        if (prevVal == curVal)
            curRow++;
        else
            curRow = 1;

        maxRow = max(maxRow, curRow);
        prevVal = curVal;
    }

    cout << maxRow << "\n";
}