#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;
    return 1;
}

vector<int> prepare() {
    vector<int> p(10001);
    for (int i = 0; i < p.size(); i++) {
        p[i] = isPrime(i * i + i + 41);
        if (i)
            p[i] += p[i - 1];
    }
    return p;
}

bool solve() {
    int l, r;
    if (!(cin >> l >> r))
        return 0;

    static vector<int> p = prepare();

    cout.precision(2);
    cout << fixed << 100.0 * (p[r] - (l ? p[l - 1] : 0)) / (r - l + 1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}