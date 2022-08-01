class Solution {
public:
    int countServers(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size(), res = 0;
        vector<int> rowCount(h), colCount(w);
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                res += a[y][x];
                rowCount[y] += a[y][x];
                colCount[x] += a[y][x];
            }
        }
        
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                res -= a[y][x] && rowCount[y] == 1 && colCount[x] == 1;
        
        return res;
    }
};