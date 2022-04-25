class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
        int res = -1, minDist;
        
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] != x && points[i][1] != y)
                continue;
            
            int dist = abs(points[i][0] - x) + abs(points[i][1] - y);
            if (res == -1 || minDist > dist) {
                res = i;
                minDist = dist;
            }
        }
        
        return res;
    }
};