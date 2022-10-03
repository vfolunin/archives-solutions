class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int width) {
        multiset<int> window;
        int res = -1e9;
        
        for (int l = 0, r = 0; r < points.size(); r++) {
            while (points[l][0] + width < points[r][0]) {
                window.erase(window.find(points[l][1] - points[l][0]));
                l++;
            }
            
            if (!window.empty())
                res = max(res, points[r][0] + points[r][1] + *window.rbegin());
            
            window.insert(points[r][1] - points[r][0]);
        }
        
        return res;
    }
};