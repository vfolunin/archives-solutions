#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

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

map<int, int> operator + (map<int, int> a, const map<int, int> &b) {
    for (auto &[key, val] : b)
        a[key] += val;
    return a;
}

void solve(int test) {
    int n;
    string s;
    cin >> n >> s;

    map<int, int> f;
    for (int i = n; i > 0; i -= s.size())
        f = f + factorize(i);

    unsigned long long res = 1, limit = 1e18;

    cout << "Case " << test << ": ";
    for (auto &[_, p] : f) {
        res *= p + 1;
        if (res > limit) {
            cout << "Infinity\n";
            return;
        }
    }
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}