#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    long long res = 1, mod = 1e12;
    for (int i = 1; i <= n; i++) {
        res *= i;
        while (res % 10 == 0)
            res /= 10;
        res %= mod;
    }

    cout << res % 10 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}