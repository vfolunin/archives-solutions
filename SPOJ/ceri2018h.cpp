#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long power, x, mod;
    cin >> power >> x >> mod;

    long long res = 0;
    for (int i = power; i >= 0; i--) {
        long long coeff;
        cin >> coeff;

        res = ((res * x + coeff) % mod + mod) % mod;
    }

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