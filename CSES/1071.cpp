#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long y, x;
    cin >> y >> x;
    y--;
    x--;

    long long level = max(y, x);
    long long start = level * level + 1;

    if (level % 2 == 0) {
        start += x;
        start += level - y;
    } else {
        start += y;
        start += level - x;
    }

    cout << start << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}