class Solution {
public:
    double champagneTower(int volume, int targetY, int targetX) {
        vector<vector<double>> res(targetY + 1, vector<double>(targetY + 1));
        res[0][0] = volume;
        
        for (int y = 0; y < targetY; y++) {
            for (int x = 0; x <= y; x++) {
                if (res[y][x] > 1) {
                    double half = (res[y][x] - 1) / 2;
                    res[y + 1][x] += half;
                    res[y + 1][x + 1] += half;
                }
            }
        }
        
        return min(res[targetY][targetX], 1.0);
    }
};