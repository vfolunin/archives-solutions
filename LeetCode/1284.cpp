class Solution {
    void flip(vector<vector<int>> &a, int y, int x) {
        int h = a.size(), w = a[0].size();
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            
            if (0 <= ty && ty < h && 0 <= tx && tx < w)
                a[ty][tx] ^= 1;
        }
        
        a[y][x] ^= 1;
    }
    
    bool test(vector<vector<int>> a, int mask) {
        int h = a.size(), w = a[0].size();
        
        for (int bit = 0; bit < h * w; bit++)
            if (mask & (1 << bit))
                flip(a, bit / w, bit % w);
        
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                if (a[y][x])
                    return 0;
        return 1;
    }
    
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }
    
public:
    int minFlips(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size(), res = 1e9;
        
        for (int mask = 0; mask < (1 << (h * w)); mask++)
            if (test(a, mask))
                res = min(res, ones(mask));
        
        return res != 1e9 ? res : -1;
    }
};