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

    int size;
    cin >> size;

    int row = 0, maxRow = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value % 2 == 0)
            row += value;
        else
            row = 0;

        maxRow = max(maxRow, row);
    }

    cout << maxRow;
}