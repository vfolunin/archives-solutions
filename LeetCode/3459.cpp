class Solution {
    int rec(vector<vector<int>> &a, int y, int x, int d, int turn, vector<vector<vector<vector<int>>>> &memo) {
        int &res = memo[y][x][d][turn];
        if (res != -1)
            return res;

        res = 1;

        static vector<int> dy = { -1, -1, 1, 1 };
        static vector<int> dx = { -1, 1, 1, -1 };

        int h = a.size(), w = a[0].size();
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < h && 0 <= tx && tx < w &&
            (a[y][x] != 2 && a[ty][tx] == 2 || a[y][x] == 2 && a[ty][tx] == 0))
            res = max(res, 1 + rec(a, ty, tx, d, turn, memo));
        
        if (!turn) {
            int td = (d + 1) % dy.size();
            ty = y + dy[td];
            tx = x + dx[td];

            if (0 <= ty && ty < h && 0 <= tx && tx < w &&
                (a[y][x] != 2 && a[ty][tx] == 2 || a[y][x] == 2 && a[ty][tx] == 0))
                res = max(res, 1 + rec(a, ty, tx, td, 1, memo));
        }

        return res;
    }

public:
    int lenOfVDiagonal(vector<vector<int>> &a) {
        vector memo(a.size(), vector(a[0].size(), vector(4, vector<int>(2, -1))));
        int res = 0;

        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                if (a[y][x] == 1)
                    for (int d = 0; d < 4; d++)
                        res = max(res, rec(a, y, x, d, 0, memo));
        
        return res;
    }
};