#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;
const long long INV = 5e8 + 4;

long long binPow(long long x, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1) * x % MOD;
    long long r = binPow(x, p / 2);
    return r * r % MOD;
}

long long mod(string &s, long long m) {
    long long res = 0;
    for (char c : s)
        res = (res * 10 + c - '0') % m;
    return res;
}

void solve(int test) {
    string s;
    cin >> s;

    long long res = binPow(3, mod(s, MOD - 1));
    res = (res + 1) % MOD;
    res = (res * INV) % MOD;

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