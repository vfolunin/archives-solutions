class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction &f, int z) {
        vector<vector<int>> res;
        
        int y = 1, x = 1000;
        while (y <= 1000 && x >= 1) {
            int value = f.f(x, y);
            if (value == z) {
                res.push_back({ x, y });
                y++;
                x--;
            } else if (value < z) {
                y++;
            } else {
                x--;
            }
        }
        
        return res;
    }
};