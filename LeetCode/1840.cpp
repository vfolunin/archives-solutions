class Solution {
public:
    int maxBuilding(int size, vector<vector<int>> &restrictions) {
        restrictions.push_back({ 1, 0 });
        restrictions.push_back({ size, size - 1 });
        sort(restrictions.begin(), restrictions.end());
        
        for (int i = 0; i + 1 < restrictions.size(); i++) {
            int xl = restrictions[i][0], yl = restrictions[i][1];
            int xr = restrictions[i + 1][0], &yr = restrictions[i + 1][1];
            yr = min(yr, yl + xr - xl);
        }
        
        for (int i = restrictions.size() - 2; i >= 0; i--) {
            int xl = restrictions[i][0], &yl = restrictions[i][1];
            int xr = restrictions[i + 1][0], yr = restrictions[i + 1][1];
            yl = min(yl, yr + xr - xl);
        }
        
        int res = 0;
        for (int i = 0; i + 1 < restrictions.size(); i++) {
            int xl = restrictions[i][0], yl = restrictions[i][1];
            int xr = restrictions[i + 1][0], yr = restrictions[i + 1][1];
            res = max(res, max(yl, yr) + (xr - xl - abs(yl - yr)) / 2);
        }
        return res;
    }
};