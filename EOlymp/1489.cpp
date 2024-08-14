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

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    for (int y = 0; y + 1 < h; y++) {
        bool ok = 1;
        for (int x = 0; x < w && ok; x++)
            ok &= a[y][x] != a[y + 1][x];

        if (ok) {
            cout << "Yes";
            return 0;
        }
    }

    for (int x = 0; x + 1 < w; x++) {
        bool ok = 1;
        for (int y = 0; y < h && ok; y++)
            ok &= a[y][x] != a[y][x + 1];

        if (ok) {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
}