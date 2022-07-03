class Solution {
public:
    int minimumLines(vector<vector<int>> &points) {
        if (points.size() <= 2)
            return points.size() - 1;
        
        sort(points.begin(), points.end());
        int res = 1;
        
        for (int i = 2; i < points.size(); i++) {
            long long dx = points[i][0] - points[i - 1][0];
            long long dy = points[i][1] - points[i - 1][1];
            long long pdx = points[i - 1][0] - points[i - 2][0];
            long long pdy = points[i - 1][1] - points[i - 2][1];
            res += dx * pdy != dy * pdx;
        }
        
        return res;
    }
};