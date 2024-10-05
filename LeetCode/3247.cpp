class Solution {
public:
    int subsequenceCount(vector<int> &a) {
        const long long MOD = 1e9 + 7;
        vector<long long> ways = { 1, 0 };

        for (int value : a) {
            if (value % 2)
                ways = { (ways[0] + ways[1]) % MOD, (ways[0] + ways[1]) % MOD };
            else
                ways = { ways[0] * 2 % MOD, ways[1] * 2 % MOD };
        }

        return ways[1];
    }
};