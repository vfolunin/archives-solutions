#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 998244353;

using Matrix = vector<vector<long long>>;

Matrix identityMatrix(int size) {
    Matrix res(size, vector<long long>(size));
    for (int i = 0; i < res.size(); i++)
        res[i][i] = 1;
    return res;
}

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix res(a.size(), vector<long long>(b[0].size()));
    for (int y = 0; y < res.size(); y++)
        for (int x = 0; x < res[0].size(); x++)
            for (int i = 0; i < a[0].size(); i++)
                res[y][x] = (res[y][x] + a[y][i] * b[i][x] % MOD) % MOD;
    return res;
}

Matrix binPow(const Matrix &m, long long p) {
    if (!p)
        return identityMatrix(m.size());
    if (p % 2)
        return binPow(m, p - 1) * m;
    Matrix r = binPow(m, p / 2);
    return r * r;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long size;
    int sumCount;
    cin >> size >> sumCount;

    unordered_set<int> sums;
    for (int i = 0; i < sumCount; i++) {
        int sum;
        cin >> sum;

        sums.insert(sum);
    }

    Matrix m(100, vector<long long>(100)), v(100, vector<long long>(1));
    for (int ab = 0; ab < 100; ab++) {
        for (int c = 0; c < 10; c++)
            if (sums.contains(ab / 10 + ab % 10 + c))
                m[ab % 10 * 10 + c][ab]++;
        v[ab][0] = ab >= 10;
    }

    long long res = 0;
    for (vector<long long> &row : binPow(m, size - 2) * v)
        res = (res + row[0]) % MOD;

    cout << res;
}