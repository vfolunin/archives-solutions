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
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < b[0].size(); x++)
            for (int i = 0; i < a[0].size(); i++)
                res[y][x] = (res[y][x] + a[y][i] * b[i][x]) % MOD;
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
    int lengthAfterTransformations(string &s, int p, vector<int> &shifts) {
        Matrix m(26, vector<long long>(26));
        for (int i = 0; i < m.size(); i++)
            for (int shift = 1; shift <= shifts[i]; shift++)
                m[(i + shift) % m.size()][i] = 1;

        Matrix a(m.size(), vector<long long>(1));
        for (char c : s)
            a[c - 'a'][0]++;
        
        Matrix b = pow(m, p) * a;

        long long res = 0;
        for (int i = 0; i < b.size(); i++)
            res = (res + b[i][0]) % MOD;
        return res;
    }
};