class Solution {
    bool rec(string &a, string &b, int ai, int bi, int diff, vector<vector<unordered_map<int, int>>> &memo) {
        if (ai > a.size() || bi > b.size())
            return 0;
        
        if (memo[ai][bi].count(diff))
            return memo[ai][bi][diff];
        int &res = memo[ai][bi][diff];
        
        if (ai == a.size() && bi == b.size())
            return res = !diff;
        
        if (isdigit(a[ai])) {
            int delta = 0;
            for (int i = ai; i < a.size() && isdigit(a[i]); i++) {
                delta = delta * 10 + a[i] - '0';
                if (rec(a, b, i + 1, bi, diff - delta, memo))
                    return res = 1;
            }
            return res = 0;
        }
        
        if (isdigit(b[bi])) {
            int delta = 0;
            for (int i = bi; i < b.size() && isdigit(b[i]); i++) {
                delta = delta * 10 + b[i] - '0';
                if (rec(a, b, ai, i + 1, diff + delta, memo))
                    return res = 1;
            }
            return res = 0;
        }
        
        if (diff > 0)
            return res = rec(a, b, ai + 1, bi, diff - 1, memo);
        
        if (diff < 0)
            return res = rec(a, b, ai, bi + 1, diff + 1, memo);
        
        return res = a[ai] == b[bi] && rec(a, b, ai + 1, bi + 1, 0, memo);
    }
    
public:
    bool possiblyEquals(string &a, string &b) {
        vector<vector<unordered_map<int, int>>> memo(a.size() + 1, vector<unordered_map<int, int>>(b.size() + 1));
        return rec(a, b, 0, 0, 0, memo);
    }
};