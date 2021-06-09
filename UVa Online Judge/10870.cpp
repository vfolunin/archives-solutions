#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Matrix {
    vector<vector<long long>> v;

    Matrix(int h, int w) : v(h, vector<long long>(w)) {}

    static Matrix eq(int size) {
        Matrix res(size, size);
        for (int i = 0; i < size; i++)
            res.v[i][i] = 1;
        return res;
    }

    Matrix mul(const Matrix &that, long long mod) const {
        Matrix res(v.size(), that.v[0].size());
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < that.v[0].size(); j++)
                for (int k = 0; k < v[0].size(); k++)
                    res.v[i][j] = (res.v[i][j] + v[i][k] * that.v[k][j]) % mod;
        return res;
    }
};

Matrix pow(const Matrix &m, long long p, long long mod) {
    if (!p)
        return Matrix::eq(m.v.size());
    if (p % 2)
        return pow(m, p - 1, mod).mul(m, mod);
    Matrix r = pow(m, p / 2, mod);
    return r.mul(r, mod);
}

bool solve() {
    long long size, p, mod;
    cin >> size >> p >> mod;

    if (!size)
        return 0;

    Matrix m(size, size);
    for (int i = 0; i < size - 1; i++)
        m.v[i][i + 1] = 1;
    for (int i = size - 1; i >= 0; i--)
        cin >> m.v[size - 1][i];

    Matrix v(size, 1);
    for (int i = 0; i < size; i++)
        cin >> v.v[i][0];

    Matrix res = pow(m, p - size, mod).mul(v, mod);

    cout << res.v[size - 1][0] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}