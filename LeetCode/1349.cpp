class Solution {
    int ones(int mask) {
        int res = 0;
        while (mask) {
            res++;
            mask &= mask - 1;
        }
        return res;
    }
    
    int rec(int row, int mask, vector<vector<char>> &a, vector<vector<int>> &memo) {
        int &res = memo[row][mask];
        if (res != -1)
            return res;
        
        for (int bit = 0; bit < a[row].size(); bit++)
            if ((mask & (1 << bit)) && (a[row][bit] == '#' || bit && (mask & (1 << (bit - 1))) || (mask & (1 << (bit + 1)))))
                return res = 0;
                                        
        if (!row)
            return res = ones(mask);
        
        res = 0;
        for (int prevMask = 0; prevMask < (1 << a[row].size()); prevMask++) {
            bool ok = 1;
            for (int bit = 0; ok && bit < a[row].size(); bit++) {
                if (mask & (1 << bit)) {
                    ok &= !bit || !(prevMask & (1 << (bit - 1)));
                    ok &= !(prevMask & (1 << (bit + 1)));
                }
            }
            
            if (ok)
                res = max(res, rec(row - 1, prevMask, a, memo) + ones(mask));
        }
        return res;
    }
    
public:
    int maxStudents(vector<vector<char>> &a) {
        vector<vector<int>> memo(a.size(), vector<int>(1 << a[0].size(), -1));
        int res = 0;
        
        for (int mask = 0; mask < (1 << a[0].size()); mask++)
            res = max(res, rec(a.size() - 1, mask, a, memo));
        
        return res;
    }
};