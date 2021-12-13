#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int w, h, minLength;
    cin >> w >> h >> minLength;

    if (!h && !w)
        return 0;

    vector<vector<int>> a(h, vector<int>(w));
    int toothpickCount = 0;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            if (a[y][x] && y)
                a[y][x] += a[y - 1][x];
        }
    }

    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (y + 1 == h || !a[y + 1][x])
                toothpickCount += a[y][x] >= minLength;

    cout << toothpickCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}