class Solution {
    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

public:
    vector<int> getGoodIndices(vector<vector<int>> &a, int remainder) {
        vector<int> res;
        for (int i = 0; i < a.size(); i++)
            if (binPow(binPow(a[i][0], a[i][1], 10), a[i][2], a[i][3]) == remainder)
                res.push_back(i);
        return res;
    }
};