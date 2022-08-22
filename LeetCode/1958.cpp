class Solution {
public:
    bool checkMove(vector<vector<char>> &a, int y, int x, char color) {
        vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
        vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int step = 1;
            while (1) {
                int ty = y + dy[d] * step;
                int tx = x + dx[d] * step;
                if (ty < 0 || ty >= a.size() || tx < 0 || tx >= a[0].size() || a[ty][tx] != 'B' + 'W' - color)
                    break;
                step++;
            }
            
            int ty = y + dy[d] * step;
            int tx = x + dx[d] * step;
            if (step > 1 && 0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == color)
                return 1;
        }
        
        return 0;
    }
};