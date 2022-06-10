class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> diag(h + w);
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                diag[y - x + w].push_back(a[y][x]);
        
        for (vector<int> &values : diag)
            sort(values.begin(), values.end());
        
        for (int y = h - 1; y >= 0; y--) {
            for (int x = w - 1; x >= 0; x--) {
                a[y][x] = diag[y - x + w].back();
                diag[y - x + w].pop_back();
            }
        }
        
        return a;
    }
};