#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, w, targetY, targetX;
    cin >> h >> w >> targetY >> targetX;
    targetY--;
    targetX--;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << (y + x == targetY + targetX || y - x == targetY - targetX ? "*" : ".");
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