#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcdex(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1, d = gcdex(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return d;
}

long long inv(long long value, long long mod) {
    long long x, y;
    return gcdex(value, mod, x, y) == 1 ? (x % mod + mod) % mod : -1;
}

void solve() {
    long long mod, value;
    cin >> mod >> value;

    long long res = inv(value, mod);

    if (res == -1)
        cout << "IMPOSSIBLE\n";
    else if (value == 1)
        cout << mod + 1 << "\n";
    else if (res)
        cout << res << "\n";
    else
        cout << mod << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        solve();
}