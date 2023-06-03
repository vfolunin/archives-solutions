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
    int trace = 0;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            cin >> a[y][x];
            if (y == x || y + x == size - 1)
                trace += a[y][x];
        }
    }
    if (size % 2)
        trace += a[size / 2][size / 2];

    int res = 0;
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            res += a[y][x] == trace;

    cout << res;
}