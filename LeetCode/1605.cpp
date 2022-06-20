class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
        int h = rowSum.size(), w = colSum.size();
        vector<vector<int>> res(h, vector<int>(w));
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                res[y][x] = min(rowSum[y], colSum[x]);
                rowSum[y] -= res[y][x];
                colSum[x] -= res[y][x];
            }
        }
        
        return res;
    }
};