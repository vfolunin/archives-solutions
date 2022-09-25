class Solution {
    bool isSquare(int n) {
        int root = sqrt(n);
        return root * root == n;
    }
    
    long long rec(int mask, int last, vector<int> &a, vector<vector<long long>> &memo) {
        long long &res = memo[mask][last];
        if (res != -1)
            return res;
        
        if (!(mask & (mask - 1)))
            return res = 1;
        
        res = 0;
        set<int> prevValues;
        
        for (int bit = 0; bit < a.size(); bit++) {
            if (bit != last && (mask & (1 << bit)) && isSquare(a[bit] + a[last])) {
                if (prevValues.count(a[bit]))
                    continue;
                prevValues.insert(a[bit]);                
                res += rec(mask ^ (1 << last), bit, a, memo);
            }
        }
        
        return res;
    }
    
public:
    int numSquarefulPerms(vector<int> &a) {
        vector<vector<long long>> memo(1 << a.size(), vector<long long>(a.size(), -1));
        
        long long res = 0;
        set<int> lastValues;
        
        for (int last = 0; last < a.size(); last++) {
            if (lastValues.count(a[last]))
                continue;
            lastValues.insert(a[last]);
            res += rec((1 << a.size()) - 1, last, a, memo);
        }
        
        return res;
    }
};