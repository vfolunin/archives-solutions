#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 100000007;

long long binPow(long long x, long long p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1) * x % MOD;
    long long r = binPow(x, p / 2);
    return r * r % MOD;
}

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    if (n < 4) {
        static vector<int> res = { 0, 1, 18, 132 };
        cout << res[n] << "\n";
    } else {
        long long res = binPow(2, n - 4);
        res = res * n % MOD;
        res = res * (n + 1) % MOD;
        res = res * ((n * n + 5 * n - 2) % MOD) % MOD;
        cout << res << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}