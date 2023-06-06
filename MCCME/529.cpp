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

    vector<vector<int>> a(10, vector<int>(10));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a[0].size(); x++)
            cin >> a[y][x];

    int res = 0;

    for (int y = 0; y < a.size(); y++) {
        int curRow = 0, maxRow = 0;
        for (int x = 0; x < a[0].size(); x++) {
            if (a[y][x])
                curRow = 0;
            else
                curRow++;
            maxRow = max(maxRow, curRow);
        }
        res = max(res, maxRow);
    }

    for (int x = 0; x < a[0].size(); x++) {
        int curRow = 0, maxRow = 0;
        for (int y = 0; y < a.size(); y++) {
            if (a[y][x])
                curRow = 0;
            else
                curRow++;
            maxRow = max(maxRow, curRow);
        }
        res = max(res, maxRow);
    }

    cout << res;
}