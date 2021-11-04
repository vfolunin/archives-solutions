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

Matrix pow(const Matrix &m, long long p) {
    if (!p)
        return { 1, 0, 0, 1 };
    if (p % 2)
        return pow(m, p - 1) * m;
    Matrix r = pow(m, p / 2);
    return r * r;
}

bool solve(int test) {
    long long p;
    cin >> p >> mod;

    if (!p && !mod)
        return 0;

    Matrix mat = pow({ 0, 1, 1, 1 }, p + 1);
    long long res = (mat.b * 2 + mod - 1) % mod;

    cout << "Case " << test << ": " << p << " " << mod << " " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}