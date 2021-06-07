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

    for (int y = 0; y < h * 3 + 1; y++) {
        for (int x = 0; x < w * 3 + 1; x++)
            cout << (y % 3 && x % 3 ? "." : "*");
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}