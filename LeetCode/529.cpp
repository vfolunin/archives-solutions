class Solution {
    void rec(vector<vector<char>> &a, int y, int x) {
        if (a[y][x] == 'M') {
            a[y][x] = 'X';
            return;
        }
        
        int h = a.size(), w = a[0].size();        
        static vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
        static vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };
        
        a[y][x] = '0';
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (0 <= ty && ty < h && 0 <= tx && tx < w && (a[ty][tx] == 'M' || a[ty][tx] == 'X'))
                a[y][x]++;
        }
        
        if (a[y][x] == '0') {
            a[y][x] = 'B';
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] == 'E')
                    rec(a, ty, tx);
            }
        }
    }
    
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &a, vector<int> &pos) {
        rec(a, pos[0], pos[1]);
        return a;
    }
};