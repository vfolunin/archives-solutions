class Solution {
    const long long MOD = 1e9 + 7;

    bool isSquareFree(int value) {
        for (int d = 2; d * d <= value; d++)
            if (value % (d * d) == 0)
                return 0;
        return 1;
    }

    long long rec(vector<pair<int, int>> &pairs, int i, long long product, long long productCount) {
        if (i == pairs.size())
            return productCount;

        long long res = rec(pairs, i + 1, product, productCount);

        auto [value, count] = pairs[i];
        if (gcd(product, value) == 1)
            res = (res + rec(pairs, i + 1, product * value, productCount * count % MOD)) % MOD;

        return res;
    }

public:
    int squareFreeSubsets(vector<int> a) {
        long long powerOfTwo = 1;
        unordered_map<int, int> count;

        for (int value : a) {
            if (value == 1)
                powerOfTwo = powerOfTwo * 2 % MOD;
            else if (isSquareFree(value))
                count[value]++;
        }

        vector<pair<int, int>> pairs(count.begin(), count.end());
        long long res = rec(pairs, 0, 1, 1) * powerOfTwo % MOD;
        res = (res - 1 + MOD) % MOD;
        return res;
    }
};