#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

using Matrix = vector<vector<long long>>;

Matrix identityMatrix(int size) {
    Matrix res(size, vector<long long>(size));
    for (int i = 0; i < res.size(); i++)
        res[i][i] = 1;
    return res;
}

Matrix mul(const Matrix &a, const Matrix &b, long long mod) {
    Matrix res(a.size(), vector<long long>(b[0].size()));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < b[0].size(); x++)
            for (int i = 0; i < a[0].size(); i++)
                res[y][x] = (res[y][x] + a[y][i] * b[i][x]) % mod;
    return res;
}

Matrix pow(const Matrix &m, long long p, long long mod) {
    if (!p)
        return identityMatrix(m.size());
    if (p % 2)
        return mul(pow(m, p - 1, mod), m, mod);
    Matrix r = pow(m, p / 2, mod);
    return mul(r, r, mod);
}

void solve() {
    Matrix v(1, vector<long long>(2));
    long long mod;
    int checkCount;
    cin >> v[0][0] >> v[0][1] >> mod >> checkCount;

    vector<pair<long long, long long>> checks(checkCount);
    for (auto &[index, value] : checks)
        cin >> index >> value;

    for (int a = 0; a <= 10; a++) {
        for (int b = 0; b <= 10; b++) {
            Matrix m = {
                { 0, b },
                { 1, a }
            };

            bool ok = 1;
            for (auto &[index, value] : checks) {
                if (mul(v, pow(m, index, mod), mod)[0][0] != value) {
                    ok = 0;
                    break;
                }
            }

            if (ok) {
                cout << a << " " << b << "\n";
                return;
            }
        }
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