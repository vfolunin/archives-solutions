#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

using Matrix = vector<vector<long long>>;

Matrix identityMatrix(int size) {
    Matrix res(size, vector<long long>(size));
    for (int i = 0; i < res.size(); i++)
        res[i][i] = 1;
    return res;
}

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix res(a.size(), vector<long long>(b[0].size()));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < b[0].size(); x++)
            for (int i = 0; i < a[0].size(); i++)
                res[y][x] = (res[y][x] + a[y][i] * b[i][x]) % MOD;
    return res;
}

Matrix pow(const Matrix &m, long long p) {
    if (!p)
        return identityMatrix(m.size());
    if (p % 2)
        return pow(m, p - 1) * m;
    Matrix r = pow(m, p / 2);
    return r * r;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Matrix v(1, vector<long long>(4));
    long long p;
    cin >> v[0][2] >> v[0][3] >> p;

    Matrix m = {
        { 0, 1, 0, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 1, 1 },
        { 0, 0, 1, 2 }
    };

    Matrix res = v * pow(m, p);

    cout << res[0][2] << " " << res[0][3];
}