#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const int MOD = 37;

using Matrix = vector<vector<int>>;

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix res(a.size(), vector<int>(b[0].size()));
    for (int y = 0; y < res.size(); y++)
        for (int x = 0; x < res[0].size(); x++)
            for (int i = 0; i < a[0].size(); i++)
                res[y][x] = (res[y][x] + a[y][i] * b[i][x] % MOD) % MOD;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    Matrix m(size, vector<int>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> m[y][x];

    string s;
    cin.ignore();
    getline(cin, s);
    s += string((size - s.size() % size) % size, ' ');

    const string symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";

    for (int i = 0; i * size < s.size(); i++) {
        Matrix v(size, vector<int>(1));
        for (int j = 0; j < size; j++)
            v[j][0] = symbols.find(s[i * size + j]);

        v = m * v;

        for (int j = 0; j < size; j++)
            cout << symbols[v[j][0]];
    }
}