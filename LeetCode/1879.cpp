class Solution {
    int ones(int mask) {
        int res = 0;
        while (mask) {
            res++;
            mask &= mask - 1;
        }
        return res;
    }
    
    int rec(int mask, vector<int> &a, vector<int> &b, vector<int> &memo) {
        int &res = memo[mask];
        if (res != -1)
            return res;
        
        int i = ones(mask) - 1;
        if (i == -1)
            return res = 0;
        
        res = 1e9;
        for (int bit = 0; bit < b.size(); bit++)
            if (mask & (1 << bit))
                res = min(res, rec(mask ^ (1 << bit), a, b, memo) + (a[i] ^ b[bit]));
        return res;        
    }
    
public:
    int minimumXORSum(vector<int> &a, vector<int> &b) {
        vector<int> memo(1 << b.size(), -1);
        return rec((1 << b.size()) - 1, a, b, memo);
    }
};