class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>> &a) {
        int y = 0, x = 0;
        set<pair<int, int>> visited = { { y, x } };

        while (1) {
            int ty = y;
            int tx = x;
            
            ty += a[y][x] == 'D';
            ty -= a[y][x] == 'U';
            tx += a[y][x] == 'R';
            tx -= a[y][x] == 'L';

            if (ty < 0 || ty >= a.size() || tx < 0 || tx >= a[0].size() || visited.contains({ ty, tx }))
                return { y, x };

            y = ty;
            x = tx;
            visited.insert({ y, x });
        }
    }
};