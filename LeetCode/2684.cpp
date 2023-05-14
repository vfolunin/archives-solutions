class Solution {
public:
    int maxMoves(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> moves(h, vector<int>(w, -1));
        for (int y = 0; y < h; y++)
            moves[y][0] = 0;
        
        int res = 0;
        for (int x = 0; x + 1 < w; x++) {
            for (int y = 0; y < h; y++) {
                int tx = x + 1;
                for (int ty = y - 1; ty <= y + 1; ty++) {
                    if (0 <= ty && ty < h && moves[y][x] != -1 && a[y][x] < a[ty][tx]) {
                        moves[ty][tx] = max(moves[ty][tx], moves[y][x] + 1);
                        res = max(res, moves[ty][tx]);
                    }
                }
            }
        }
        return res;
    }
};