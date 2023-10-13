#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool gcd(long long a, long long b, long long c, long long d) {
    while (1) {
        if (a == c && b == d)
            return 1;
        if (a < b)
            swap(a, b);
        if (!b)
            return 0;
        if (b == d)
            return a >= c && (a - c) % b == 0;
        a %= b;
    }
    return 0;
}

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << (gcd(a, b, c, d) ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}