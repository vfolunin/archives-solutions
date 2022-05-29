class Solution {
public:
    int numSquares(int n) {
        vector<int> res(n + 1, 1e9);
        res[0] = 0;
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j * j <= i; j++)
                res[i] = min(res[i], res[i - j * j] + 1);
        
        return res[n];
    }
};