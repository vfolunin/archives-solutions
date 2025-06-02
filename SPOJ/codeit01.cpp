#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getCatalan(int n) {
    const long long MOD = 1e9 + 7;
    vector<long long> res = { 1 };
    for (int i = 1; i <= n; i++) {
        res.push_back(0);
        for (int j = 0; j < i; j++)
            res.back() = (res.back() + res[j] * res[i - 1 - j]) % MOD;
    }
    return res.back();
}

void solve() {
    int n;
    cin >> n;

    cout << getCatalan(n) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}