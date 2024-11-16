#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
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
    for (int y = 0; y < res.size(); y++)
        for (int x = 0; x < res[0].size(); x++)
            for (int i = 0; i < a[0].size(); i++)
                res[y][x] = (res[y][x] + a[y][i] * b[i][x] % MOD) % MOD;
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

    int a, b, c;
    long long n;
    cin >> a >> b >> c >> n;

    Matrix m = {
        { 0, 1, 0 },
        { 0, 0, 1 },
        { 1, 1, 1 }
    }, v = {
        { a }, { b }, { c }
    };

    cout << (pow(m, n - 1) * v)[0][0];
}