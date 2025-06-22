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

    int row = 0, maxRow = 0;

    for (char c; cin >> c; ) {
        if (c == '0')
            row = 0;
        else
            row++;

        maxRow = max(maxRow, row);
    }

    cout << maxRow;
}