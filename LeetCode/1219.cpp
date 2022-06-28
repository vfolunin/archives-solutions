class Solution {
    int rec(vector<vector<int>> &a, int y, int x) {
        if (y < 0 || y >= a.size() || x < 0 || x >= a[0].size() || !a[y][x])
            return 0;
        
        int value = a[y][x], res = value;
        a[y][x] = 0;
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            res = max(res, value + rec(a, ty, tx));
        }
        
        a[y][x] = value;
        return res;
    }
    
public:
    int getMaximumGold(vector<vector<int>> &a) {
        int res = 0;
        
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                res = max(res, rec(a, y, x));
        
        return res;
    }
};