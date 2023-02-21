class Solution {
public:
    int numberOfCleanRooms(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        int y = 0, x = 0, d = 1;

        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };

        set<tuple<int, int, int>> seen;

        while (!seen.count({ y, x, d })) {
            seen.insert({ y, x, d });
            a[y][x] = 2;

            for (int i = 0; i < 4; i++) {
                int ty = y + dy[d];
                int tx = x + dx[d];

                if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] != 1) {
                    y = ty;
                    x = tx;
                    break;
                }
                
                d = (d + 1) % 4;
            }
        }

        int res = 0;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                res += a[y][x] == 2;
        return res;
    }
};