#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 9;

struct Matrix {
    vector<vector<long long>> v;

    Matrix() : v(3, vector<long long>(3)) {
        v[0][0] = v[1][1] = v[2][2] = 1;
    }

    Matrix(const vector<vector<long long>> &v) : v(v) {}

    Matrix operator * (const Matrix &that) const {
        Matrix res;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < that.v[0].size(); j++) {
                res.v[i][j] = 0;
                for (int k = 0; k < v[0].size(); k++)
                    res.v[i][j] = (res.v[i][j] + v[i][k] * that.v[k][j]) % MOD;
            }
        }
        return res;
    }
};

Matrix pow(const Matrix &m, long long p) {
    if (!p)
        return Matrix();
    if (p % 2)
        return pow(m, p - 1) * m;
    Matrix r = pow(m, p / 2);
    return r * r;
}

bool solve() {
    long long p;
    cin >> p;

    if (!p)
        return 0;

    Matrix a({ { 0, 1, 2 } });
    Matrix b({ { 0, 0, 1 }, { 1, 0, 1 }, { 0, 1, 1 } });

    cout << (a * pow(b, p - 1)).v[0][0] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}