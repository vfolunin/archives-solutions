class Solution {
    int rec(int h, int w, int y, int x, int a, int b, string prevRow,
            vector<vector<vector<vector<unordered_map<string, int>>>>> &memo) {
        if (y == h)
            return 0;
        
        if (x == w)
            return rec(h, w, y + 1, 0, a, b, prevRow, memo);
            
        if (memo[y][x][a][b].count(prevRow))
            return memo[y][x][a][b][prevRow];
        int &res = memo[y][x][a][b][prevRow];
        
        char prevUp = prevRow[x];
        
        prevRow[x] = ' ';
        res = rec(h, w, y, x + 1, a, b, prevRow, memo);
        
        if (a) {
            prevRow[x] = 'a';
            
            int cur = 120;
            if (y) {
                if (prevUp == 'a')
                    cur -= 60;
                if (prevUp == 'b')
                    cur -= 10;
            }
            if (x) {
                if (prevRow[x - 1] == 'a')
                    cur -= 60;
                if (prevRow[x - 1] == 'b')
                    cur -= 10;
            }
            
            res = max(res, cur + rec(h, w, y, x + 1, a - 1, b, prevRow, memo));
        }
        
        if (b) {
            prevRow[x] = 'b';
            
            int cur = 40;
            if (y) {
                if (prevUp == 'a')
                    cur -= 10;
                if (prevUp == 'b')
                    cur += 40;
            }
            if (x) {
                if (prevRow[x - 1] == 'a')
                    cur -= 10;
                if (prevRow[x - 1] == 'b')
                    cur += 40;
            }
            
            res = max(res, cur + rec(h, w, y, x + 1, a, b - 1, prevRow, memo));
        }
        
        prevRow[x] = prevUp;
        
        return res;
    }
    
public:
    int getMaxGridHappiness(int h, int w, int a, int b) {
        vector<vector<vector<vector<unordered_map<string, int>>>>> memo(
            h, vector<vector<vector<unordered_map<string, int>>>>(
            w, vector<vector<unordered_map<string, int>>>(
            a + 1, vector<unordered_map<string, int>>(b + 1, unordered_map<string, int>()))));
        return rec(h, w, 0, 0, a, b, string(w, ' '), memo);
    }
};