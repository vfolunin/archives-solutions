class Solution {
public:
    int robotSim(vector<int> &ops, vector<vector<int>> &points) {
        set<pair<int, int>> pointSet;
        for (vector<int> &point : points)
            pointSet.insert({ -point[1], point[0] });
        
        int y = 0, x = 0, d = 0, res = 0;
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        
        for (int op : ops) {
            if (op == -2) {
                d = (d + 3) % 4;
            } else if (op == -1) {
                d = (d + 1) % 4;
            } else {
                for (int i = 0; i < op; i++) {
                    int ty = y + dy[d];
                    int tx = x + dx[d];
                    
                    if (pointSet.count({ ty, tx }))
                        break;
                    
                    y = ty;
                    x = tx;
                    res = max(res, y * y + x * x);
                }
            }
        }
        
        return res;
    }
};