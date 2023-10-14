class Solution {
public:
    int countSubMultisets(vector<int> &a, int l, int r) {
        map<int, int> count;
        for (int value : a)
            count[value]++;
        
        const long long MOD = 1e9 + 7;
        vector<long long> ways(r + 1);
        ways[0] = 1;
        
        for (auto &[value, maxCount] : count) {
            if (!value)
                continue;

            vector<long long> pWays = ways;
            for (int sum = value; sum < ways.size(); sum++)
                pWays[sum] = (ways[sum] + pWays[sum - value]) % MOD;

            for (int sum = 0; sum < ways.size(); sum++) {
                ways[sum] = pWays[sum];
                if (int from = sum - value * (maxCount + 1); from >= 0)
                    ways[sum] -= pWays[from];
                ways[sum] = (ways[sum] % MOD + MOD) % MOD;
            }
        }
        
        long long res = 0;
        for (int sum = l; sum <= r; sum++)
            res = (res + ways[sum]) % MOD;
        return res * (count[0] + 1) % MOD;
    }
};