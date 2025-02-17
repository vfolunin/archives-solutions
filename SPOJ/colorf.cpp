#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 9;

long long binPow(long long x, long long p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1) * x % MOD;
    long long r = binPow(x, p / 2);
    return r * r % MOD;
}

long long inv(long long x) {
    return binPow(x, MOD - 2);
}

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i % MOD;
    return res;
}

void solve() {
    int size;
    cin >> size;

    vector<int> a(size);
    int sum = 0;
    for (int &value : a) {
        cin >> value;
        sum += value;
    }

    long long res = factorial(sum);
    for (int value : a)
        res = res * inv(factorial(value)) % MOD;

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