#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

const int MOD = 10;

using Matrix = vector<vector<int>>;

Matrix identityMatrix(int size) {
    Matrix res(size, vector<int>(size));
    for (int i = 0; i < res.size(); i++)
        res[i][i] = 1;
    return res;
}

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix res(a.size(), vector<int>(b[0].size()));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < b[0].size(); x++)
            for (int i = 0; i < a[0].size(); i++)
                res[y][x] = (res[y][x] + a[y][i] * b[i][x]) % MOD;
    return res;
}

Matrix pow(const Matrix &m, unsigned long long p) {
    if (!p)
        return identityMatrix(m.size());
    if (p % 2)
        return pow(m, p - 1) * m;
    Matrix r = pow(m, p / 2);
    return r * r;
}

bool solve() {
    unsigned long long n;
    if (!(cin >> n))
        return 0;

    Matrix m = {
        { 0, 1 },
        { 1, 1 }
    };

    Matrix res = pow(m, n);

    cout << res[1][1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}