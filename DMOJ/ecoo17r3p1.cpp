#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int w, h;
    if (!(cin >> w >> h))
        return 0;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    int res = 0;
    for (int y = 0; y < h; y++) {
        int sum = 0;
        for (int x = 0; x < w; x++)
            sum += a[y][x];
        if (sum % 13 == 0)
            res += sum / 13;
    }
    for (int x = 0; x < w; x++) {
        int sum = 0;
        for (int y = 0; y < h; y++)
            sum += a[y][x];
        if (sum % 13 == 0)
            res += sum / 13;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}