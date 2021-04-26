#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e13 + 7;

void solve(int test) {
    long long size, l, r;
    cin >> size >> l >> r;

    long long res = 0, prod = 1, ways = size * size;
    for (int i = 1; i < l; i++) {
        prod = (prod * ways) % MOD;
        ways--;
    }
    for (int i = l; i <= r; i++) {
        prod = (prod * ways) % MOD;
        res = (res + prod) % MOD;
        ways--;
    }

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