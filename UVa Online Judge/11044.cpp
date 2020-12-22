#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;
    cout << (h / 3) * (w / 3) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}