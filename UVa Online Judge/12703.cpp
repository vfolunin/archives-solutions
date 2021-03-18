#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<int, long long> factorize(int n) {
    map<int, long long> f;
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

map<int, long long> operator + (map<int, long long> a, const map<int, long long> &b) {
    for (auto &[key, val] : b)
        a[key] += val;
    return a;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<map<int, long long>> v(n + 1);
    v[0] = factorize(a);
    v[1] = factorize(b);
    for (int i = 2; i <= n; i++)
        v[i] = v[i - 1] + v[i - 2];

    for (auto &[key, val] : v.back())
        cout << key << " " << val << "\n";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}