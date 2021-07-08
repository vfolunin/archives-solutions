#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> red(n);
    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            int color;
            cin >> color;
            red[a] += color;
            red[b] += color;
        }
    }

    int bad = 0;
    for (int i = 0; i < n; i++) {
        int blue = n - 1 - red[i];
        bad += red[i] * blue;
    }
    bad /= 2;

    int res = n * (n - 1) * (n - 2) / 6;
    res -= bad;

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}