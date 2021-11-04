#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e4;

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

Matrix binPow(const Matrix &m, long long p, long long mod) {
    if (!p)
        return Matrix::eq(m.v.size());
    if (p % 2)
        return binPow(m, p - 1, mod).mul(m, mod);
    Matrix r = binPow(m, p / 2, mod);
    return r.mul(r, mod);
}

bool solve() {
    int shipCount, leapCount, start, finish;
    if (!(cin >> shipCount >> leapCount >> start >> finish))
        return 0;

    Matrix startVector(1, shipCount);
    startVector.v[0][start - 1]++;

    Matrix matrix(shipCount, shipCount);
    for (int a = 0; a < shipCount; a++) {
        for (int i = 0; i < 4; i++) {
            int b;
            cin >> b;
            matrix.v[a][b - 1]++;
        }
    }

    Matrix resVector = startVector.mul(binPow(matrix, leapCount, MOD), MOD);

    cout << resVector.v[0][finish - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}