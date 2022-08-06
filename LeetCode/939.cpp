class Solution {
    int getCode(int x, int y) {
        return x * 5e4 + y;
    }
    
public:
    int minAreaRect(vector<vector<int>> &points) {
        unordered_set<int> pointSet;
        for (vector<int> &point : points)
            pointSet.insert(getCode(point[0], point[1]));
        
        int res = 0;
        
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (points[i][0] == points[j][0] || points[i][1] == points[j][1])
                    continue;
                
                if (pointSet.count(getCode(points[i][0], points[j][1])) &&
                    pointSet.count(getCode(points[j][0], points[i][1]))) {
                    int dx = abs(points[i][0] - points[j][0]);
                    int dy = abs(points[i][1] - points[j][1]);
                    int area = dx * dy;
                    if (!res || res > area)
                        res = area;
                }
            }
        }
        
        return res;
    }
};