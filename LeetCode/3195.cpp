class Solution {
public:
    int minimumArea(vector<vector<int>> &a) {
        int minY = 1e9, minX = 1e9, maxY = 0, maxX = 0;
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (a[y][x]) {
                    minY = min(minY, y);
                    minX = min(minX, x);
                    maxY = max(maxY, y);
                    maxX = max(maxX, x);
                }
            }
        }
        return (maxY - minY + 1) * (maxX - minX + 1);
    }
};