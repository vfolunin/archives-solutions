#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

struct Matrix {
    long long a, b, c, d;

    Matrix operator * (const Matrix &that) const {
        return {
            (a * that.a + b * that.c) % MOD, (a * that.b + b * that.d) % MOD,
            (c * that.a + d * that.c) % MOD, (c * that.b + d * that.d) % MOD
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

long long fib(int n) {
    return pow({ 0, 1, 1, 1 }, n).b;
}

long long fibSum(int n) {
    return (fib(n + 2) + MOD - 1) % MOD;
}

void solve() {
    int l, r;
    cin >> l >> r;

    long long res = fibSum(r);
    if (l)
        res = (res - fibSum(l - 1) + MOD) % MOD;

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