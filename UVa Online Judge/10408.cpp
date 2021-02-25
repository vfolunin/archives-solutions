#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Fraction {
    int n, d;

    bool operator < (const Fraction &that) const {
        return n * that.d < that.n * d;
    }
};

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool solve() {
    int n, k;
    if (!(cin >> n >> k))
        return 0;
    k--;

    vector<Fraction> f;
    for (int a = 1; a <= n; a++)
        for (int b = 1; b <= a; b++)
            if (gcd(a, b) == 1)
                f.push_back({ b, a });

    sort(f.begin(), f.end());

    cout << f[k].n << "/" << f[k].d << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}