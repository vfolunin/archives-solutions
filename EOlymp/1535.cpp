#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

long long c(int n, int k) {
    if (k > n || k < 0)
        return 0;

    static vector<vector<long long>> memo(201, vector<long long>(201, -1));
    if (memo[n][k] != -1)
        return memo[n][k];

    if (k == 0 || k == n)
        return memo[n][k] = 1;

    return memo[n][k] = (c(n - 1, k) + c(n - 1, k - 1)) % MOD;
}

long long arranges(int n, int seen) {
    if (seen > n || seen < 0)
        return 0;

    static vector<vector<long long>> memo(201, vector<long long>(201, -1));
    if (memo[n][seen] != -1)
        return memo[n][seen];

    if (seen == n)
        return memo[n][seen] = 1;

    return memo[n][seen] = (arranges(n - 1, seen) * (n - 1) + arranges(n - 1, seen - 1)) % MOD;
}

bool solve() {
    long long n, seenFromLeft, seenFromRight;
    if (!(cin >> n >> seenFromLeft >> seenFromRight))
        return 0;

    long long res = 0;
    for (long long left = 0, right = n - 1; left < n; left++, right--)
        res = (res + c(left + right, right) * arranges(left, seenFromLeft - 1) % MOD * arranges(right, seenFromRight - 1) % MOD) % MOD;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}