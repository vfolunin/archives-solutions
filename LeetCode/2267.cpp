class Solution {
public:
    bool hasValidPath(vector<vector<char>> &a) {
        if (a[0][0] == ')')
            return 0;
        
        int h = a.size(), w = a[0].size();
        
        vector<vector<vector<int>>> can(h, vector<vector<int>>(w, vector<int>(101)));
        can[0][0][1] = 1;
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (!y && !x)
                    continue;
                
                if (a[y][x] == '(') {
                    for (int b = 1; b <= 100; b++)
                        can[y][x][b] = y && can[y - 1][x][b - 1] || x && can[y][x - 1][b - 1];
                } else {
                    for (int b = 0; b < 100; b++)
                        can[y][x][b] = y && can[y - 1][x][b + 1] || x && can[y][x - 1][b + 1];
                }
            }
        }
        
        return can[h - 1][w - 1][0];
    }
};