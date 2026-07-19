#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

using Matrix = vector<vector<int>>;

Matrix mul(const Matrix &a, const Matrix &b, int mod) {
    Matrix res(a.size(), vector<int>(b[0].size()));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < b[0].size(); x++)
            for (int i = 0; i < a[0].size(); i++)
                res[y][x] = (res[y][x] + 1LL * a[y][i] * b[i][x]) % mod;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, mod, queryCount;
    cin >> a >> b >> mod >> queryCount;

    vector<Matrix> matrixPowers(60);
    matrixPowers[0] = {
        { 0, 1 },
        { b, a }
    };
    for (int i = 1; i < matrixPowers.size(); i++)
        matrixPowers[i] = mul(matrixPowers[i - 1], matrixPowers[i - 1], mod);

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        long long index;
        cin >> a >> b >> index;

        Matrix m = {
            { 1, 0 },
            { 0, 1 }
        };
        for (int bit = 0; bit < matrixPowers.size(); bit++)
            if (index & (1LL << bit))
                m = mul(m, matrixPowers[bit], mod);

        Matrix v = { { a }, { b } };

        cout << mul(m, v, mod)[0][0] << "\n";
    }
}