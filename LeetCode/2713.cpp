class Solution {
public:
    int maxIncreasingCells(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<pair<int, pair<int, int>>> cells;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                cells.push_back({ a[y][x], { y, x } });
        
        sort(cells.rbegin(), cells.rend());
        
        vector<vector<int>> pathSize(h, vector<int>(w));
        vector<int> rowPathSize(h), colPathSize(w);
        
        for (int i = 0, j = 0; i < cells.size(); ) {
            for ( ; j < cells.size() && cells[i].first == cells[j].first; j++) {
                auto [y, x] = cells[j].second;
                pathSize[y][x] = 1 + max(rowPathSize[y], colPathSize[x]);
            }
            for ( ; i < j; i++) {
                auto [y, x] = cells[i].second;
                rowPathSize[y] = max(rowPathSize[y], pathSize[y][x]);
                colPathSize[x] = max(colPathSize[x], pathSize[y][x]);
            }
        }
        
        int res = 0;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                res = max(res, pathSize[y][x]);
        return res;
    }
};