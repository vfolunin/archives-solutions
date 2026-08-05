#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

using Matrix = vector<vector<long long>>;

istream &operator >> (istream &in, Matrix &m) {
    for (int y = 0; y < m.size(); y++)
        for (int x = 0; x < m[0].size(); x++)
            in >> m[y][x];
    return in;
}

Matrix generate(int h, int w) {
    static minstd_rand generator;
    static uniform_int_distribution<int> distribution(1, 5);
    Matrix res(h, vector<long long>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            res[y][x] = distribution(generator);
    return res;
}

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix res(a.size(), vector<long long>(b[0].size()));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < b[0].size(); x++)
            for (int i = 0; i < a[0].size(); i++)
                res[y][x] += a[y][i] * b[i][x];
    return res;
}

void solve() {
    vector<int> size(4);
    for (int &size : size)
        cin >> size;

    Matrix a(size[0], vector<long long>(size[1]));
    Matrix b(size[2], vector<long long>(size[3]));
    Matrix c(size[0], vector<long long>(size[3]));
    cin >> a >> b >> c;

    if (size[1] != size[2]) {
        cout << "Inner matrix dimensions must agree\n";
    } else {
        Matrix m = generate(1, size[0]);

        cout << (m * a * b == m * c ? "AC\n" : "WA\n");
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}