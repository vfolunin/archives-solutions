class Solution {
public:
    int countLatticePoints(vector<vector<int>> &circles) {
        set<pair<int, int>> points;
        
        for (vector<int> &circle : circles) {
            int cx = circle[0], cy = circle[1], r = circle[2];
            for (int y = -r; y <= r; y++)
                for (int x = -r; x <= r; x++)
                    if (y * y + x * x <= r * r)
                        points.insert({ cy + y, cx + x });
        }
        
        return points.size();
    }
};