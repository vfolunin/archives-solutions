#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long f(long long n) {
    if (!n)
        return 1;
    if (n % 4 == 1)
        return 0;
    if (n % 4 == 2)
        return n;
    if (n % 4 == 3)
        return 1;
    return n + 1;
}

void solve() {
    long long l, r;
    cin >> l >> r;

    long long res = f(l);
    for (int i = 1; i < 4 && l + i <= r; i++)
        res &= f(l + i);

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