class Solution {
    bool rec(vector<vector<int>> &a, int y, int x, int step) {
        a[y][x] = step;    
        if (step == a.size() * a[0].size() - 1)
            return 1;
    
        static vector<int> dy = { -2, -1, 1, 2, 2, 1, -1, -2 };
        static vector<int> dx = { 1, 2, 2, 1, -1, -2, -2, -1 };

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
    
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == -1 && rec(a, ty, tx, step + 1))
                return 1;
        }

        a[y][x] = -1;
        return 0;
    }

public:
    vector<vector<int>> tourOfKnight(int h, int w, int y, int x) {
        vector<vector<int>> a(h, vector<int>(w, -1));
        rec(a, y, x, 0);
        return a;
    }
};