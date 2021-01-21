#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Matrix {
    long long a, b, c, d;
};

Matrix mul(const Matrix &m1, const Matrix &m2, long long mod) {
    long long a = (m1.a * m2.a + m1.b * m2.c) % mod;
    long long b = (m1.a * m2.b + m1.b * m2.d) % mod;
    long long c = (m1.c * m2.a + m1.d * m2.c) % mod;
    long long d = (m1.c * m2.b + m1.d * m2.d) % mod;
    return { a, b, c, d };
}

Matrix binPow(const Matrix &m, int p, long long mod) {
    if (!p)
        return { 1, 0, 0, 1 };
    if (p % 2)
        return mul(binPow(m, p - 1, mod), m, mod);
    Matrix r = binPow(m, p / 2, mod);
    return mul(r, r, mod);
}

bool solve() {
    int p, modP;
    if (!(cin >> p >> modP))
        return 0;

    cout << binPow({ 0, 1, 1, 1 }, p, 1 << modP).b << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}