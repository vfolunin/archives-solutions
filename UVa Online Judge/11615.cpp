#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int maxLevel, a, b;
    cin >> maxLevel >> a >> b;

    if (a > b)
        swap(a, b);

    int bLevel = 0;
    while (b) {
        bLevel++;
        b /= 2;
    }
    bLevel = maxLevel - bLevel + 1;

    long long res = (1LL << maxLevel) - 1;
    res -= (1LL << bLevel) - 2;

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