class Solution {
    int getSum(vector<int> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
    
    pair<int, int> rec(vector<int> &p, int from, vector<pair<int, int>> &memo) {
        pair<int, int> &res = memo[from];
        if (res.first != -1e9)
            return res;
        
        if (from == p.size())
            return res = { 0, 0 };

        for (int i = 1; i <= 3; i++)
            if (from + i <= p.size())
                res.first = max(res.first, getSum(p, from, from + i - 1) + rec(p, from + i, memo).second);
        
        res.second = getSum(p, from, p.size() - 1) - res.first;
        
        return res;
    }
    
public:
    string stoneGameIII(vector<int> &p) {
        partial_sum(p.begin(), p.end(), p.begin());
        
        vector<pair<int, int>> memo(p.size() + 1, { -1e9, -1e9 });
        auto [a, b] = rec(p, 0, memo);
        
        if (a > b)
            return "Alice";
        else if (a < b)
            return "Bob";
        else
            return "Tie";
    }
};