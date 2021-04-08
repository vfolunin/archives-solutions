#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long mod;

struct Matrix {
    long long a, b, c, d;

    Matrix operator * (const Matrix &that) const {
        return {
            (a * that.a + b * that.c) % mod, (a * that.b + b * that.d) % mod,
            (c * that.a + d * that.c) % mod, (c * that.b + d * that.d) % mod
        };
    }
};

Matrix pow(const Matrix &m, int p) {
    if (!p)
        return { 1, 0, 0, 1 };
    if (p % 2)
        return pow(m, p - 1) * m;
    Matrix r = pow(m, p / 2);
    return r * r;
}

void solve() {
    long long a, b, n, m;
    cin >> a >> b >> n >> m;

    mod = 1;
    for (int i = 0; i < m; i++)
        mod *= 10;

    Matrix mat = pow({ 0, 1, 1, 1 }, n);
    cout << (a * mat.a + b * mat.c) % mod << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}