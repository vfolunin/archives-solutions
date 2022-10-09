class Solution {
public:
    int numWays(int stepCount, int size) {
        const long long MOD = 1e9 + 7;
        
        vector<long long> ways(501);
        ways[0] = 1;
        
        for (int i = 0; i < stepCount; i++) {
            vector<long long> nextWays = ways;
            for (int j = 0; j < nextWays.size() && j < size; j++) {
                if (j)
                    nextWays[j] += ways[j - 1];
                if (j + 1 < nextWays.size())
                    nextWays[j] += ways[j + 1];
                nextWays[j] %= MOD;
            }
            ways.swap(nextWays);
        }
        
        return ways[0];
    }
};