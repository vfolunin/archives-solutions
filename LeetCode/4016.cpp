class Solution {
    int get(vector<vector<int>> &a, int y, int x) {
        return 0 <= y && y < a.size() && 0 <= x && x < a[0].size() ? a[y][x] : 0;
    }
    
public:
    int maxArea(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();

        vector<vector<int>> ul(h, vector<int>(w));
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                if (a[y][x])
                    ul[y][x] = 1 + min({ get(ul, y - 1, x - 1), get(ul, y - 1, x), get(ul, y, x - 1 ) });
        
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                ul[y][x] = max({ get(ul, y - 1, x), get(ul, y, x - 1), get(ul, y, x) });

        vector<vector<int>> dr(h, vector<int>(w));
        for (int y = h - 1; y >= 0; y--)
            for (int x = w - 1; x >= 0; x--)
                if (a[y][x])
                    dr[y][x] = 1 + min({ get(dr, y, x + 1), get(dr, y + 1, x), get(dr, y + 1, x + 1 ) });
        
        for (int y = h - 1; y >= 0; y--)
            for (int x = w - 1; x >= 0; x--)
                dr[y][x] = max({ get(dr, y, x), get(dr, y, x + 1), get(dr, y + 1, x) });
        
        int res = 0;
        for (int y = 0; y + 1 < h; y++)
            res = max(res, min(ul[y][w - 1], dr[y + 1][0]));
        for (int x = 0; x + 1 < w; x++)
            res = max(res, min(ul[h - 1][x], dr[0][x + 1]));
        return res * res;
    }
};