#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int r, c, h, w;
    cin >> r >> c >> h >> w;

    for (int y = 0; y < r * h; y++) {
        for (int x = 0; x < c * w; x++)
            cout << (((y / h) + (x / w)) % 2 ? "." : "X");
        cout << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}