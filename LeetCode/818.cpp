class Solution {
    int rec(int target) {
        static vector<int> memo(1e5, 1e9);
        int &res = memo[target];
        if (res != 1e9)
            return res;
        
        if (!target)
            return res = 0;
        
        int len = 0;
        while (1 << len <= target)
            len++;
        
        if (target == (1 << len) - 1)
            return res = len;
        
        res = rec((1 << len) - 1 - target) + len + 1;
        for (int i = 0; i < len; i++)
            res = min(res, rec(target - (1 << (len - 1)) + (1 << i)) + len + i + 1);
        return res;
    }
    
public:
    int racecar(int target) {
        return rec(target);
    }
};