class Solution {
public:
    int countOfPairs(vector<int> &a) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> ways(a.size(), vector<int>(51));

        for (int last = 0; last <= a[0]; last++)
            ways[0][last] = 1;

        for (int i = 1; i < a.size(); i++)
            for (int last = 0; last <= a[i]; last++)
                for (int prev = 0; prev <= last; prev++)
                    if (a[i - 1] >= prev && a[i - 1] - prev >= a[i] - last)
                        ways[i][last] = (ways[i][last] + ways[i - 1][prev]) % MOD;
        
        int res = 0;
        for (int last = 0; last <= a.back(); last++)
            res = (res + ways[a.size() - 1][last]) % MOD;
        return res;
    }
};