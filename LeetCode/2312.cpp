class Solution {
    long long rec(int h, int w, vector<vector<int>> &price, vector<vector<long long>> &memo) {
        long long &res = memo[h][w];
        if (res != -1)
            return res;
        
        res = price[h][w];        
        for (int y = 1; y < h; y++)
            res = max(res, rec(y, w, price, memo) + rec(h - y, w, price, memo));
        for (int x = 1; x < w; x++)
            res = max(res, rec(h, x, price, memo) + rec(h, w - x, price, memo));
        return res;
    }
    
public:
    long long sellingWood(int h, int w, vector<vector<int>> &prices) {
        vector<vector<int>> price(h + 1, vector<int>(w + 1));
        for (vector<int> &p : prices)
            price[p[0]][p[1]] = p[2];
        
        vector<vector<long long>> memo(h + 1, vector<long long>(w + 1, -1));
        
        return rec(h, w, price, memo);
    }
};