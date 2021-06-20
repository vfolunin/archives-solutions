#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std; 

void solve() {
    int h, w, y, x;
    cin >> h >> w >> y >> x;

    cout << (((h - 1 - y) ^ (w - 1 - x) ^ y ^ x) ? "Gretel\n" : "Hansel\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}