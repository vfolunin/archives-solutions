class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3)
            return n - 1;
        
        vector<long long> res(n + 1);
        iota(res.begin() + 1, res.begin() + 4, 1);
        
        for (int i = 4; i <= n; i++)
            for (int j = 1; j <= 3; j++)
                res[i] = max(res[i], res[i - j] * j);
        
        return res[n];
    }
};