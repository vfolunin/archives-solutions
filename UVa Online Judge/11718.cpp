#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

void solve(int test) {
    long long n, k, mod;
    cin >> n >> k >> mod;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum = (sum + x) % mod;
    }

    long long res = sum * binPow(n, k - 1, mod) * k % mod;

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}