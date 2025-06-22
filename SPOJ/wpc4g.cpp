#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;

    vector<vector<long long>> a(h + 1, vector<long long>(w + 1));
    for (int y = 1; y < a.size(); y++) {
        a[y][0] = y;
        for (int x = 1; x < a[0].size(); x++)
            for (int py = 1; py <= y; py++)
                a[y][x] += a[py][x - 1];
    }

    cout << a[h][w] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}