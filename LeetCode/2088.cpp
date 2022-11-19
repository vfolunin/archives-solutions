class Solution {
    int solve(vector<vector<int>> a) {
        int res = 0;
        for (int y = 1; y < a.size(); y++) {
            for (int x = 1; x + 1 < a[0].size(); x++) {
                if (a[y][x])
                    a[y][x] += min({ a[y - 1][x - 1], a[y - 1][x], a[y - 1][x + 1] });
                if (a[y][x] > 1)
                    res += a[y][x] - 1;
            }
        }
        return res;
    }
    
public:
    int countPyramids(vector<vector<int>> &a) {
        int res = solve(a);
        
        for (int l = 0, r = a.size() - 1; l < r; l++, r--)
            for (int x = 0; x < a[0].size(); x++) 
                swap(a[l][x], a[r][x]);
        
        res += solve(a);
        
        return res;
    }
};