class Solution {
    int area(vector<vector<int>> &a, int y1, int x1, int y2, int x2) {
        int minY = 1e9, minX = 1e9, maxY = 0, maxX = 0;
        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++) {
                if (a[y][x]) {
                    minY = min(minY, y);
                    minX = min(minX, x);
                    maxY = max(maxY, y);
                    maxX = max(maxX, x);
                }
            }
        }
        return minY == 1e9 ? 1e8 : (maxY - minY + 1) * (maxX - minX + 1);
    }

public:
    int minimumSum(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size(), res = 1e9;

        for (int y1 = 0; y1 + 1 < h; y1++) {
            for (int y2 = y1 + 1; y2 + 1 < h; y2++)
                res = min(res, area(a, 0, 0, y1, w - 1) + area(a, y1 + 1, 0, y2, w - 1) + area(a, y2 + 1, 0, h - 1, w - 1));
            for (int x = 0; x + 1 < w; x++) {
                res = min(res, area(a, 0, 0, y1, x) + area(a, 0, x + 1, y1, w - 1) + area(a, y1 + 1, 0, h - 1, w - 1));
                res = min(res, area(a, 0, 0, y1, w - 1) + area(a, y1 + 1, 0, h - 1, x) + area(a, y1 + 1, x + 1, h - 1, w - 1));
            }
        }

        for (int x1 = 0; x1 + 1 < w; x1++) {
            for (int x2 = x1 + 1; x2 + 1 < w; x2++)
                res = min(res, area(a, 0, 0, h - 1, x1) + area(a, 0, x1 + 1, h - 1, x2) + area(a, 0, x2 + 1, h - 1, w - 1));
            for (int y = 0; y + 1 < h; y++) {
                res = min(res, area(a, 0, 0, y, x1) + area(a, y + 1, 0, h - 1, x1) + area(a, 0, x1 + 1, h - 1, w - 1));
                res = min(res, area(a, 0, 0, h - 1, x1) + area(a, 0, x1 + 1, y, w - 1) + area(a, y + 1, x1 + 1, h - 1, w - 1));
            }
        }
        
        return res;
    }
};