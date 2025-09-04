#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long n, mod;
    cin >> n >> mod;

    if (n >= mod) {
        cout << "0\n";
    } else {
        long long res = 1;
        for (int i = 2; i <= n; i++)
            res = res * i % mod;
        cout << res << "\n";
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