class Solution {
public:
    int twoEggDrop(int n) {
        vector<int> res(n + 1, 1e9);
        res[1] = 1;
        
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= i; j++)
                res[i] = min(res[i], 1 + max(j - 1, res[i - j]));
        
        return res[n];
    }
};