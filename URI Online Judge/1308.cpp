#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    long long l = 0, r = 2e9;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (m * (m + 1) / 2 <= n)
            l = m;
        else
            r = m;
    }

    cout << l << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}