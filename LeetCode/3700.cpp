const long long MOD = 1e9 + 7;

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

Matrix pow(const Matrix &m, long long p) {
    if (!p)
        return identityMatrix(m.size());
    if (p % 2)
        return pow(m, p - 1) * m;
    Matrix r = pow(m, p / 2);
    return r * r;
}

class Solution {
public:
    int zigZagArrays(int size, int l, int r) {
        int offset = r - l + 1;

        Matrix v(1, vector<long long>(offset * 2));
        for (int value = l; value <= r; value++) {
            v[0][value - l] = 1;
            v[0][offset + value - l] = 1;
        }

        Matrix m(offset * 2, vector<long long>(offset * 2));
        for (int value = l; value <= r; value++) {
            for (int prevValue = r; prevValue > value; prevValue--)
                m[prevValue - l + offset][value - l] = 1;
            for (int prevValue = l; prevValue < value; prevValue++)
                m[prevValue - l][value - l + offset] = 1;
        }

        Matrix ways = v * pow(m, size - 1);

        long long res = 0;
        for (long long value : ways[0])
            res = (res + value) % MOD;
        return res;
    }
};