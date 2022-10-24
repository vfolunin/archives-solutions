class Solution {
public:
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location) {
        vector<double> angles;
        int zeros = 0;
        for (vector<int> &point : points) {
            if (point == location)
                zeros++;
            else
                angles.push_back(atan2(point[1] - location[1], point[0] - location[0]));
        }
        
        int angleCount = angles.size();        
        sort(angles.begin(), angles.end());
        for (int i = 0; i < angleCount; i++)
            angles.push_back(angles[i] + 2 * acos(-1));
        
        double delta = angle / 180.0 * acos(-1);
        
        int res = 0;        
        for (int l = 0, r = 0; l < angleCount; l++) {
            while (angles[r] - angles[l] <= delta + 1e-9)
                r++;
            res = max(res, r - l);
        }        
        return min<int>(res + zeros, points.size());
    }
};