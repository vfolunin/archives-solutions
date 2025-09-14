class Solution {
public:
    int countStableSubsequences(vector<int> &a) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> ways(2, vector<long long>(3));

        for (int value : a) {
            int bit = value % 2;
            ways[bit] = {
                0,
                (ways[bit][1] + 1 + ways[!bit][1] + ways[!bit][2]) % MOD,
                (ways[bit][2] + ways[bit][1]) % MOD
            };
        }

        return (ways[0][1] + ways[0][2] + ways[1][1] + ways[1][2]) % MOD;
    }
};