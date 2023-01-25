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

    int h, w;
    cin >> h >> w;

    vector<int> maxRow(h);

    for (int y = 0; y < h; y++) {
        int curRow = 0;

        for (int x = 0; x < w; x++) {
            int value;
            cin >> value;

            if (value)
                curRow = 0;
            else
                curRow++;

            maxRow[y] = max(maxRow[y], curRow);
        }
    }

    int needRow;
    cin >> needRow;

    for (int y = 0; y < h; y++) {
        if (maxRow[y] >= needRow) {
            cout << y + 1;
            return 0;
        }
    }

    cout << 0;
}