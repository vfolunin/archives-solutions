#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <bit>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    long long res;
    if (n <= 2)
        res = n;
    else if (n & (n - 1))
        res = bit_ceil((unsigned long long)n);
    else
        res = n * 2 - 1;
    res--;

    const long long MOD = 1e9 + 7;
    cout << res % MOD << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}