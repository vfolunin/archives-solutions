#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<int, int> factorize(int n) {
    map<int, int> factorization;

    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
    }
    if (n != 1)
        factorization[n]++;

    return factorization;
}

long long factPower(long long f, int p) {
    long long res = 0;
    while (f) {
        f /= p;
        res += f;
    }
    return res;
}

void solve() {
    long long n;
    int base;
    cin >> n >> base;

    long long res = 1e18;
    for (auto &[p, k] : factorize(base))
        res = min(res, factPower(n, p) / k);

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