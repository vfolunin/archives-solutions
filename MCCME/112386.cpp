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

    int x;
    cin >> x;
    x--;

    stable_sort(a.begin(), a.end(), [&](auto &lhs, auto &rhs) {
        return lhs[x] > rhs[x];
    });

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}