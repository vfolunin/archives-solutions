class Solution {
    static const long long MOD = 1e9 + 7;

    long long getWaysWithMinDiff(vector<int> &a, int targetSize, int minDiff) {
        vector ways(targetSize + 1, vector<long long>(a.size()));

        for (int last = 0; last < a.size(); last++)
            ways[1][last] = 1;
        
        for (int size = 2; size <= targetSize; size++)
            for (int last = 0; last < a.size(); last++)
                for (int prev = 0; prev < last; prev++)
                    if (a[last] - a[prev] >= minDiff)
                        ways[size][last] = (ways[size][last] + ways[size - 1][prev]) % MOD;

        long long res = 0;
        for (int last = 0; last < a.size(); last++)
            res = (res + ways[targetSize][last]) % MOD;
        return res;
    }

    long long getWays(vector<int> &a, int targetSize, int diff) {
        return (getWaysWithMinDiff(a, targetSize, diff) - getWaysWithMinDiff(a, targetSize, diff + 1) + MOD) % MOD;
    }

public:
    int sumOfPowers(vector<int> &a, int targetSize) {
        sort(a.begin(), a.end());

        unordered_set<int> diffs;
        for (int i = 0; i < a.size(); i++)
            for (int j = i; j < a.size(); j++)
                diffs.insert(a[j] - a[i]);
        
        long long res = 0;
        for (int diff : diffs)
            res = (res + getWays(a, targetSize, diff) * diff % MOD) % MOD;
        return res;
    }
};