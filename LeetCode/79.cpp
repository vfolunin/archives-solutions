class Solution {
    bool rec(vector<vector<char>> &a, int y, int x, string &s, int i) {
        if (i == s.size() - 1)
            return 1;
        
        a[y][x] = '#';
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() &&
                a[ty][tx] == s[i + 1] && rec(a, ty, tx, s, i + 1))
                return 1;
        }
        
        a[y][x] = s[i];
                
        return 0;
    }
    
public:
    bool exist(vector<vector<char>> &a, string s) {
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                if (a[y][x] == s[0] && rec(a, y, x, s, 0))
                    return 1;
        return 0;
    }
};