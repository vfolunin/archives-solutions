class Solution {
public:
    int countPartitions(vector<int> &a, int limit) {
        long long sum = 0;
        for (int value : a)
            sum += value;
        
        if (sum < limit * 2)
            return 0;

        const long long MOD = 1e9 + 7;

        vector<long long> ways(limit);
        ways[0] = 1;

        for (int weight : a)
            for (int totalWeight = limit - 1; totalWeight >= weight; totalWeight--)
                ways[totalWeight] = (ways[totalWeight] + ways[totalWeight - weight]) % MOD;
        
        long long res = 1;
        for (int i = 0; i < a.size(); i++)
            res = res * 2 % MOD;
        
        for (int totalWeight = 0; totalWeight < limit; totalWeight++)
            res = (res - ways[totalWeight] * 2 % MOD + MOD) % MOD;
        
        return res;
    }
};