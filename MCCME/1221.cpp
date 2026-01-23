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

    int h, w, cellCount;
    cin >> h >> w >> cellCount;

    vector<vector<int>> a(h + 2, vector<int>(w + 2));
    for (int i = 0; i < cellCount; i++) {
        int y, x;
        cin >> y >> x;

        a[y][x] = 1;
    }

    int res = 0;
    for (int y = 0; y <= h; y++) {
        for (int x = 0; x <= w; x++) {
            res += a[y][x] != a[y + 1][x];
            res += a[y][x] != a[y][x + 1];
        }
    }

    cout << res;
}