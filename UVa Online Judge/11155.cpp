#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    long long x, a, b, mod, n;
    cin >> x >> a >> b >> mod >> n;

    vector<long long> pCount(mod);
    pCount[0]++;

    long long p = x % mod, res = pCount[p];
    pCount[p]++;

    for (int i = 1; i < n; i++) {
        x = (a * x + b) % mod + 1;
        p = (p + x) % mod;
        res += pCount[p];
        pCount[p]++;
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