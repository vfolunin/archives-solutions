class Solution {
public:
    int numSpecial(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        vector<int> rowSum(h), colSum(w);
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                rowSum[y] += a[y][x];
                colSum[x] += a[y][x];
            }
        }
        
        int res = 0;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                res += a[y][x] == 1 && rowSum[y] == 1 && colSum[x] == 1;
        return res;
    }
};