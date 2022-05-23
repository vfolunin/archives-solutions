class Solution {
    int c(int n, int k) {
        static vector<vector<int>> memo(200, vector<int>(200, -1));
        int &res = memo[n][k];
        if (res != -1)
            return res;
        
        if (k == 0 || k == n)
            return res = 1;
        
        return res = c(n - 1, k - 1) + c(n - 1, k);
    }
    
public:
    int uniquePaths(int h, int w) {
        return c(h + w - 2, h - 1);
    }
};