class Solution {
public:
    bool checkValidGrid(vector<vector<int>> &a) {
        vector<int> ys(a.size() * a.size());
        vector<int> xs(a.size() * a.size());
        
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a.size(); x++) {
                ys[a[y][x]] = y;
                xs[a[y][x]] = x;
            }
        }
        
        if (ys[0] || xs[0])
            return 0;
        
        for (int i = 1; i < ys.size(); i++)
            if (abs(ys[i] - ys[i - 1]) * abs(xs[i] - xs[i - 1]) != 2)
                return 0;
        
        return 1;
    }
};