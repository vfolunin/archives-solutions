#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

long long rec(int n, int k, int d) {
    if (n < 0)
        return 0;

    static vector<vector<vector<long long>>> memo(1001, vector<vector<long long>>(1001, vector<long long>(11, -1)));
    long long &res = memo[n][k][d];
    if (res != -1)
        return res;

    if (!n)
        return res = !k;
    
    if (k == 1)
        return res = n;

    return res = (rec(n - 1, k, d) + rec(n - d, k - 1, d)) % MOD;
}

void solve(int test) {
    int n, k, d;
    cin >> n >> k >> d;

    long long res;
    if (k == 1)
        res = rec(n, k, d);
    else
        res = (rec(n - d, k, d) + d * rec(n - 2 * d + 1, k - 1, d)) % MOD;

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