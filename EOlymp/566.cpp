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

    vector<int> res(2);
    for (int rectH = 1; rectH <= h; rectH++)
        for (int rectW = 1; rectW <= w; rectW++)
            res[rectH != rectW] += (h - rectH + 1) * (w - rectW + 1);

    cout << res[0] << " " << res[1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}