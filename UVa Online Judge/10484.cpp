#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<int, int> factorize(int n) {
    if (n < 0)
        n = -n;
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

map<int, int> sum(map<int, int> a, const map<int, int> &b) {
    for (auto &[key, val] : b)
        a[key] += val;
    return a;
}

vector<map<int, int>> prepare() {
    vector<map<int, int>> p(101);
    for (int i = 2; i < p.size(); i++)
        p[i] = sum(p[i - 1], factorize(i));
    return p;
}

bool hasAll(const map<int, int> &a, const map<int, int> &b) {
    for (auto &[key, val] : b)
        if (!a.count(key) || a.at(key) < val)
            return 0;
    return 1;
}

bool solve() {
    int n, d;
    cin >> n >> d;

    if (!n && !d)
        return 0;

    static vector<map<int, int>> p = prepare();
    map<int, int> &fFactors = p[n];
    map<int, int> dFactors = factorize(d);

    if (hasAll(fFactors, dFactors)) {
        long long res = 1;
        for (auto &[key, val] : fFactors)
            res *= val - dFactors[key] + 1;
        cout << res << "\n";
    } else {
        cout << "0\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}