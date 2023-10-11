#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long n, a, b;
    cin >> n >> a >> b;

    long long res = (a / n) * (b / n) * n;
    res += (a % n + 1) * (b / n);
    res += (b % n + 1) * (a / n);
    res += max(a % n + b % n - n + 1, 0LL);

    cout << res << "\n";
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