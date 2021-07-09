#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Matrix {
    long long a, b, c, d;

    Matrix operator * (const Matrix &that) const {
        return {
            (a * that.a + b * that.c), (a * that.b + b * that.d),
            (c * that.a + d * that.c), (c * that.b + d * that.d)
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

bool solve() {
    long long sum, prod, n;
    if (!(cin >> sum >> prod >> n))
        return 0;

    Matrix m = { sum, -prod, 1, 0 };
    m = pow(m, n);

    cout << sum * m.c + 2 * m.d << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}