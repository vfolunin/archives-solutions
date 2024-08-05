class Solution {
public:
    int minFlips(vector<vector<int>> &a) {
        int rowsFlipCount = 0;
        for (int y = 0; y < a.size(); y++) {
            int flipCount = 0;
            for (int l = 0, r = a[0].size() - 1; l < r; l++, r--)
                flipCount += a[y][l] != a[y][r];
            rowsFlipCount += flipCount;
        }
        
        int colsFlipCount = 0;
        for (int x = 0; x < a[0].size(); x++) {
            int flipCount = 0;
            for (int l = 0, r = a.size() - 1; l < r; l++, r--)
                flipCount += a[l][x] != a[r][x];
            colsFlipCount += flipCount;
        }

        return min(rowsFlipCount, colsFlipCount);
    }
};