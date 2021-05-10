#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Matrix {
    vector<vector<unsigned long long>> m;

    Matrix(int h, int w) : m(h, vector<unsigned long long>(w)) {}

    Matrix operator * (const Matrix &that) const {
        Matrix res(m.size(), that.m[0].size());
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < that.m[0].size(); j++) {
                res.m[i][j] = 0;
                for (int k = 0; k < m[0].size(); k++)
                    res.m[i][j] += m[i][k] * that.m[k][j];
            }
        }
        return res;
    }
};

Matrix pow(const Matrix &m, int p) {
    if (!p) {
        Matrix res(m.m.size(), m.m.size());
        for (int i = 0; i < res.m.size(); i++)
            res.m[i][i] = 1;
        return res;
    }
    if (p % 2)
        return pow(m, p - 1) * m;
    Matrix r = pow(m, p / 2);
    return r * r;
}

void solve() {
    int ruleCount;
    cin >> ruleCount;

    Matrix m(128, 128);
    for (int i = 0; i < m.m.size(); i++)
        m.m[i][i] = 1;
    for (int i = 0; i < ruleCount; i++) {
        string rule;
        cin >> rule;
        m.m[rule[0]][rule[0]] = 0;
        for (int j = 3; j < rule.size(); j++)
            m.m[rule[0]][rule[j]]++;
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string start;
        char c;
        int p;
        cin >> start >> c >> p;

        Matrix v(1, 128);
        for (char c : start)
            v.m[0][c]++;

        cout << (v * pow(m, p)).m[0][c] << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}