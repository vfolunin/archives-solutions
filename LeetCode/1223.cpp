class Solution {
    const long long MOD = 1e9 + 7;
    
    long long rec(int size, int last, int count, vector<int> &limit, vector<vector<vector<long long>>> &memo) {
        if (size < 0 || size < count)
            return 0;
        
        long long &res = memo[size][last][count];
        if (res != -1)
            return res;
        
        if (size == count)
            return res = 1;
        
        if (count > 1)
            return res = rec(size - 1, last, count - 1, limit, memo);
        
        res = 0;
        for (int prev = 1; prev <= 6; prev++)
            if (prev != last)
                for (int prevCount = 1; prevCount <= limit[prev - 1]; prevCount++)
                    res = (res + rec(size - 1, prev, prevCount, limit, memo)) % MOD;
        return res;
    }
    
public:
    int dieSimulator(int size, vector<int> &limit) {
        vector<vector<vector<long long>>> memo(size + 1, vector<vector<long long>>(7, vector<long long>(16, -1)));
        long long res = 0;
        
        for (int last = 1; last <= 6; last++)
            for (int count = 1; count <= limit[last - 1]; count++)
                res = (res + rec(size, last, count, limit, memo)) % MOD;
        
        return res;
    }
};