class Solution {
public:
    int countBattleships(vector<vector<char>>& a) {
        int h = a.size(), w = a[0].size(), res = 0;
        
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                res += a[y][x] == 'X' && (!y || a[y - 1][x] == '.') && (!x || a[y][x - 1] == '.');
        
        return res;
    }
};