class Solution {
    const long long MOD = 1e9 + 7;
    
    long long rec(vector<vector<int>> &a, int y, int x, vector<vector<long long>> &memo) {
        long long &res =  memo[y][x];
        if (res != -1)
            return res;
        
        res = 1;
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[y][x] < a[ty][tx])
                res = (res + rec(a, ty, tx, memo)) % MOD;
        }
        
        return res;
    }
    
public:
    int countPaths(vector<vector<int>> &a) {
        long long res = 0;
        
        vector<vector<long long>> memo(a.size(), vector<long long>(a[0].size(), -1));
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                res = (res + rec(a, y, x, memo)) % MOD;
        
        return res;
    }
};