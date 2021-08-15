#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int childCount;
    cin >> childCount;

    long long mod = 0;
    for (int i = 0; i < childCount; i++) {
        long long x;
        cin >> x;
        mod = (mod + x) % childCount;
    }

    cout << (mod == 0 ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}