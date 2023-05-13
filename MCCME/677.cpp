#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 10;

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

    vector<int> a(3);
    long long p;
    cin >> a[0] >> a[1] >> a[2] >> p;

    if (p <= 3) {
        cout << a[p - 1];
        return 0;
    }
    
    Matrix m = {
        { 0, 0, 1 },
        { 1, 0, 1 },
        { 0, 1, 1 }
    };
    Matrix res = Matrix(1, a) * pow(m, p - 3);

    cout << res[0][2];
}