#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

const long long MOD = 1e9 + 7;

using Matrix = vector<vector<long long>>;

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix res(a.size(), vector<long long>(b[0].size()));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < b[0].size(); x++)
            for (int i = 0; i < a[0].size(); i++)
                res[y][x] = (res[y][x] + a[y][i] * b[i][x]) % MOD;
    return res;
}

Matrix read(int h, int w) {
    Matrix res(h, vector<long long>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> res[y][x];
    return res;
}

Matrix generate(int h, int w) {
    static minstd_rand generator;
    Matrix res(h, vector<long long>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            res[y][x] = generator() % MOD;
    return res;
}

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    Matrix a = read(size, size);
    Matrix b = read(size, size);
    Matrix c = read(size, size);
    Matrix m = generate(1, size);

    cout << (m * a * b == m * c ? "YES\n" : "NO\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}