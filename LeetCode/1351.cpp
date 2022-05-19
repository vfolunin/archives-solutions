class Solution {
public:
    int countNegatives(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size(), res = 0;
        
        for (int y = 0, x = w - 1; y < h; y++) {
            while (x >= 0 && a[y][x] < 0)
                x--;
            res += w - 1 - x;
        }
        
        return res;
    }
};