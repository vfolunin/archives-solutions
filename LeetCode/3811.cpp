class Solution {
public:
    int alternatingXOR(vector<int> &a, int xor0, int xor1) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> ways(a.size() + 1, vector<long long>(2));
        vector<unordered_map<int, long long>> waysSum(2);
        ways[0][1] = 1;
        waysSum[1][0] = ways[0][1];

        int prefixXor = 0;
        for (int size = 1; size <= a.size(); size++) {
            prefixXor ^= a[size - 1];
            ways[size][0] = waysSum[1][prefixXor ^ xor0];
            ways[size][1] = waysSum[0][prefixXor ^ xor1];
            waysSum[0][prefixXor] = (waysSum[0][prefixXor] + ways[size][0]) % MOD;
            waysSum[1][prefixXor] = (waysSum[1][prefixXor] + ways[size][1]) % MOD;
        }

        return (ways.back()[0] + ways.back()[1]) % MOD;
    }
};