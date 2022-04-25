class Solution {
public:
    bool checkStraightLine(vector<vector<int>> &points) {
        int diffX = points[1][0] - points[0][0];
        int diffY = points[1][1] - points[0][1];
        
        for (int i = 2; i < points.size(); i++)
            if ((points[i][0] - points[0][0]) * diffY !=
                (points[i][1] - points[0][1]) * diffX)
                return 0;
        
        return 1;
    }
};