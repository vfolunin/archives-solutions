vector<int> prefixFunction(const string &s) {
    vector<int> p(s.size());
    for (int i = 1; i < s.size(); i++) {
        int border = p[i - 1];
        while (border > 0 && s[i] != s[border])
            border = p[border - 1];
        p[i] = border + (s[i] == s[border]);
    }
    return p;
}

const long long MOD = 1e9 + 7;

using Matrix = vector<vector<long long>>;

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix res(a.size(), vector<long long>(b[0].size()));
    for (int y = 0; y < res.size(); y++)
        for (int x = 0; x < res[0].size(); x++)
            for (int i = 0; i < a[0].size(); i++)
                res[y][x] = (res[y][x] + a[y][i] * b[i][x] % MOD) % MOD;
    return res;
}

Matrix identityMatrix(int size) {
    Matrix res(size, vector<long long>(size));
    for (int i = 0; i < res.size(); i++)
        res[i][i] = 1;
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
    int numberOfWays(string &a, string &b, long long moves) {
        vector<int> p = prefixFunction(b + " " + a + a), shifts;
        for (int i = 0; i + 1 < p.size(); i++)
            if (p[i] == b.size())
                shifts.push_back(i - 2 * b.size());
        
        if (shifts.empty())
            return 0;

        Matrix args = { { 0, 1, MOD - 1 } };
        long long aSize = a.size();
        Matrix transitions = {
            { 0, 0, 0},
            { aSize - 1, aSize - 1, 0 },
            { 0, 1, MOD - 1 }
        };
        Matrix coeffs = args * pow(transitions, moves - 1);
        long long coeff0 = coeffs[0][0], coeff1 = coeffs[0][1];

        long long res = 0;
        for (int shift : shifts)
            res = (res + (shift ? coeff1 : coeff0)) % MOD;
        return res;
    }
};