#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e8 + 7;

map<int, int> factorize(int n) {
    map<int, int> f;
    for (int d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            f[d]++;
            n /= d;
        }
    }
    if (n > 1)
        f[n]++;
    return f;
}

bool solve(int test) {
    int n, p, z;
    cin >> n >> p >> z;

    if (!n && !p && !z)
        return 0;

    map<int, int> f = factorize(n);
    long long resAdd = 1, resSub = 1;

    for (auto &[_, fp] : f) {
        resAdd = (resAdd * (1 + fp * p / z)) % MOD;
        resSub = (resSub * (1 + fp * p / (z + 1))) % MOD;
    }

    cout << "Case " << test << ": " << (resAdd - resSub + MOD) % MOD << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}