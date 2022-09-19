class Solution {
    const long long MOD = 1e9 + 7;
    
    long long rec(vector<string> &a, int fromY, int fromX, int cuts, vector<vector<vector<long long>>> &memo) {
        long long &res = memo[fromY][fromX][cuts];
        if (res != -1)
            return res;
        
        set<int> ys, xs;
        for (int y = fromY; y < a.size(); y++) {
            for (int x = fromX; x < a[0].size(); x++) {
                if (a[y][x] == 'A') {
                    ys.insert(y);
                    xs.insert(x);
                }
            }
        }
        
        if (ys.empty())
            return res = 0;
        
        if (cuts == 1) 
            return res = *prev(ys.end()) - *ys.begin() + *prev(xs.end()) - *xs.begin();
        
        res = 0;
        for (int y = *ys.begin(); y < *prev(ys.end()); y++)
            res = (res + rec(a, y + 1, fromX, cuts - 1, memo)) % MOD;
        for (int x = *xs.begin(); x < *prev(xs.end()); x++)
            res = (res + rec(a, fromY, x + 1, cuts - 1, memo)) % MOD;
        return res;
    }
    
public:
    int ways(vector<string> &a, int pieces) {
        if (pieces == 1) {
            for (int y = 0; y < a.size(); y++)
                for (int x = 0; x < a[0].size(); x++)
                    if (a[y][x] == 'A')
                        return 1;
            return 0;
        }
        
        vector<vector<vector<long long>>> memo(a.size(), vector<vector<long long>>(a[0].size(), vector<long long>(pieces, -1)));
        return rec(a, 0, 0, pieces - 1, memo);
    }
};