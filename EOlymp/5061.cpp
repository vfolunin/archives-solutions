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

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> a[y][x];

    vector<vector<int>> res(size, vector<int>(size));
    res[0][0] = a[0][0];

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (y && x)
                res[y][x] = max(res[y][x], res[y - 1][x - 1]);
            if (y)
                res[y][x] = max(res[y][x], res[y - 1][x]);
            if (x)
                res[y][x] = max(res[y][x], res[y][x - 1]);
            res[y][x] += a[y][x];
        }
    }

    cout << res.back().back();
}