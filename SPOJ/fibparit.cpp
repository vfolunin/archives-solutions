#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

using Matrix = vector<vector<long long>>;

Matrix identityMatrix(int size, long long mod) {
    Matrix res(size, vector<long long>(size));
    for (int i = 0; i < res.size(); i++)
        res[i][i] = 1 % mod;
    return res;
}

Matrix multiply(const Matrix &a, const Matrix &b, long long mod) {
    Matrix res(a.size(), vector<long long>(b[0].size()));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < b[0].size(); x++)
            for (int i = 0; i < a[0].size(); i++)
                res[y][x] = (res[y][x] + a[y][i] * b[i][x]) % mod;
    return res;
}

Matrix pow(const Matrix &m, long long p, long long mod) {
    if (!p)
        return identityMatrix(m.size(), mod);
    if (p % 2)
        return multiply(pow(m, p - 1, mod), m, mod);
    Matrix r = pow(m, p / 2, mod);
    return multiply(r, r, mod);
}

void solve() {
    long long n, mod;
    cin >> n >> mod;

    Matrix m = {
        { 0, 1 },
        { 1, 1 }
    };

    Matrix res = pow(m, n, mod);

    cout << res[0][1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}