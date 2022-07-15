class Solution {
    int winner(int limit, int target, int mask, vector<int> &memo) {
        int &res = memo[mask];
        if (res != -1)
            return res;
        
        int sum = 0;
        for (int bit = 0; bit < limit; bit++)
            if (mask & (1 << bit))
                sum += bit + 1;
        
        if (sum >= target)
            return res = 2;
        
        for (int bit = 0; bit < limit; bit++)
            if (!(mask & (1 << bit)) && winner(limit, target, mask ^ (1 << bit), memo) == 2)
                return res = 1;
        
        return res = 2;
    }
    
public:
    bool canIWin(int limit, int target) {
        if (!target)
            return 1;
        
        if (limit * (limit + 1) / 2 < target)
            return 0;
        
        vector<int> memo(1 << limit, -1);
        return winner(limit, target, 0, memo) == 1;
    }
};