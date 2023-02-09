class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();

        vector<pair<int, int>> cells;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                cells.push_back({ y, x });
        
        sort(cells.begin(), cells.end(), [&](auto &lhs, auto &rhs) {
            return a[lhs.first][lhs.second] < a[rhs.first][rhs.second];
        });

        vector<int> rowMax(h), colMax(w);
        for (auto &[y, x] : cells) 
            a[y][x] = rowMax[y] = colMax[x] = max(rowMax[y], colMax[x]) + 1;

        return a;
    }
};