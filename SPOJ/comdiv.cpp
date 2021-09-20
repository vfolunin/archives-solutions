#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int divisorCount(int n) {
    int res = 0;
    for (int d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            res++;
            res += d * d != n;
        }
    }
    return res;
}

void solve() {
    int a, b;
    cin >> a >> b;

    cout << divisorCount(gcd(a, b)) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}