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
    int maxValue = 0;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            maxValue = max(maxValue, a[y][x]);
        }
    }

    for (int x = 0; x < w; x++) {
        bool ok = 0;
        for (int y = 0; y < h; y++)
            ok |= a[y][x] == maxValue;

        if (ok) {
            for (int y = 0; y < h; y++)
                cout << a[y][x] << " ";
            cout << "\n";
        }
    }
}