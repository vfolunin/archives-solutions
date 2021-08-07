#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

struct Matrix {
    vector<vector<long long>> v;

    Matrix(int h, int w) : v(h, vector<long long>(w)) {}

    static Matrix eq(int size) {
        Matrix res(size, size);
        for (int i = 0; i < size; i++)
            res.v[i][i] = 1;
        return res;
    }

    Matrix mul(const Matrix &that, long long mod) const {
        Matrix res(v.size(), that.v[0].size());
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < that.v[0].size(); j++)
                for (int k = 0; k < v[0].size(); k++)
                    res.v[i][j] = (res.v[i][j] + v[i][k] * that.v[k][j]) % mod;
        return res;
    }
};

Matrix binPow(const Matrix &m, long long p, long long mod) {
    if (!p)
        return Matrix::eq(m.v.size());
    if (p % 2)
        return binPow(m, p - 1, mod).mul(m, mod);
    Matrix r = binPow(m, p / 2, mod);
    return r.mul(r, mod);
}

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

map<int, int> prepareMasks() {
    map<int, int> res;
    for (int mask = 0; mask < 128; mask++)
        if (ones(mask) == 4)
            res[mask] = res.size();
    return res;
}

int getId(int mask) {
    static map<int, int> masks = prepareMasks();
    return masks[mask];
}

Matrix prepareMatrix() {
    Matrix res(35, 35);

    for (int mask = 0; mask < 128; mask++) {
        if (ones(mask) != 4)
            continue;

        vector<int> pos;
        for (int bit = 0; bit < 7; bit++)
            if (mask & (1 << bit))
                pos.push_back(bit);

        for (int dMask = 0; dMask < 16; dMask++) {
            int nextMask = 0;

            for (int bit = 0; bit < 4; bit++) {
                int d = (dMask & (1 << bit)) ? 1 : -1;
                int nextPos = pos[bit] + d;
                if (0 <= nextPos && nextPos < 7)
                    nextMask |= 1 << nextPos;
            }

            if (ones(nextMask) == 4)
                res.v[getId(mask)][getId(nextMask)] = 1;
        }
    }

    return res;
}

void solve() {
    int p;
    cin >> p;

    int startMask = 0;
    for (int bit = 0; bit < 7; bit++) {
        int x;
        cin >> x;
        if (x)
            startMask |= 1 << bit;
    }

    Matrix startVector(1, 35);
    startVector.v[0][getId(startMask)] = 1;

    static Matrix transMatrix = prepareMatrix();
    Matrix resVector = startVector.mul(binPow(transMatrix, p - 1, MOD), MOD);

    long long res = 0;
    for (long long x : resVector.v[0])
        res = (res + x) % MOD;

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}