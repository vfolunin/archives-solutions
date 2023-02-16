class Solution {
public:
    int maxKilledEnemies(vector<vector<char>> &a) {
        int h = a.size(), w = a[0].size();

        vector<vector<int>> wallRow(h), wallCol(w), enemyRow(h), enemyCol(w);

        for (int y = 0; y < h; y++)
            wallRow[y].push_back(-1e9);
        for (int x = 0; x < w; x++)
            wallCol[x].push_back(-1e9);

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (a[y][x] == 'W') {
                    wallRow[y].push_back(x);
                    wallCol[x].push_back(y);
                } else if (a[y][x] == 'E') {
                    enemyRow[y].push_back(x);
                    enemyCol[x].push_back(y);
                }
            }
        }

        for (int y = 0; y < h; y++)
            wallRow[y].push_back(1e9);
        for (int x = 0; x < w; x++)
            wallCol[x].push_back(1e9);

        int res = 0;

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (a[y][x] == '0') {
                    auto wallRowR = lower_bound(wallRow[y].begin(), wallRow[y].end(), x);
                    auto wallRowL = prev(wallRowR);
                    auto enemyRowR = upper_bound(enemyRow[y].begin(), enemyRow[y].end(), *wallRowR - 1);
                    auto enemyRowL = lower_bound(enemyRow[y].begin(), enemyRow[y].end(), *wallRowL + 1);
                    int enemyRowCount = enemyRowR - enemyRowL;
                    
                    auto wallColR = lower_bound(wallCol[x].begin(), wallCol[x].end(), y);
                    auto wallColL = prev(wallColR);
                    auto enemyColR = upper_bound(enemyCol[x].begin(), enemyCol[x].end(), *wallColR - 1);
                    auto enemyColL = lower_bound(enemyCol[x].begin(), enemyCol[x].end(), *wallColL + 1);
                    int enemyColCount = enemyColR - enemyColL;

                    res = max(res, enemyRowCount + enemyColCount);
                }
            }
        }

        return res;
    }
};