class Solution {
    vector<int> rec(string &s, int l, int r, vector<vector<vector<int>>> &memo) {
        vector<int> &res = memo[l][r];
        if (!res.empty())
            return res;
        
        for (int i = l; i <= r; i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                for (int a : rec(s, l, i - 1, memo)) {
                    for (int b : rec(s, i + 1, r, memo)) {
                        if (s[i] == '+')
                            res.push_back(a + b);
                        else if (s[i] == '-')
                            res.push_back(a - b);
                        else
                            res.push_back(a * b);
                    }
                }
            }
        }
        
        if (res.empty())
            res.push_back(stoi(s.substr(l, r - l + 1)));
        
        return res;
    }
    
public:
    vector<int> diffWaysToCompute(string &s) {
        vector<vector<vector<int>>> memo(s.size(), vector<vector<int>>(s.size()));
        return rec(s, 0, s.size() - 1, memo);
    }
};