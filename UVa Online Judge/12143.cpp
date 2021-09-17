#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 10007;

int binPow(int x, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1) * x % MOD;
    int r = binPow(x, p / 2);
    return r * r % MOD;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static const vector<int> num = { 107, 9984, 71, 9904, 16 };
    static const vector<int> pow = { 10, 8, 6, 4, 2 };
    static const vector<int> den = { 1843, 5255, 8682, 6839, 2605 };

    int res = 0;
    for (int i = 0; i < 5; i++)
        res = (res + num[i] * binPow(n % MOD, pow[i]) % MOD * den[i] % MOD) % MOD;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}