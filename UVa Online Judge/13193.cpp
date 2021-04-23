#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    vector<int> seen(32);
    for (int i = 0; i < 32; i++) {
        seen[n & 31] = 1;
        n = ((n & 1) << 31) | (n >> 1);
    }

    cout << (!count(seen.begin(), seen.end(), 0) ? "yes\n" : "no\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}