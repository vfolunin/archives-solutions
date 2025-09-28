class Solution {
    static const long long MOD = 1e9 + 7;

    long long getSum(vector<long long> &p, int l, int r) {
        if (l > r)
            return 0;
        return ((p[r] - (l ? p[l - 1] : 0)) % MOD + MOD) % MOD;
    }

public:
    int zigZagArrays(int size, int l, int r) {
        vector ways(size, vector(2, vector<long long>(2001)));
        for (int value = l; value <= r; value++) {
            ways[0][0][value] = (ways[0][0][value - 1] + 1) % MOD;
            ways[0][1][value] = (ways[0][1][value - 1] + 1) % MOD;
        }
        
        for (int i = 1; i < size; i++) {
            for (int value = l; value <= r; value++) {
                ways[i][0][value] = (ways[i][0][value - 1] + getSum(ways[i - 1][1], value + 1, r)) % MOD;
                ways[i][1][value] = (ways[i][1][value - 1] + getSum(ways[i - 1][0], l, value - 1)) % MOD;
            }
        }

        return (getSum(ways.back()[0], l, r) + getSum(ways.back()[1], l, r)) % MOD;
    }
};