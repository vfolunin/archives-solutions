class Solution {
    void rec(string &s, int i, string &bs, int balance, unordered_set<string> &res) {
        if (i == s.size()) {
            if (!balance) {
                if (!res.empty() && res.begin()->size() < bs.size())
                    res = { bs };
                else if (res.empty() || res.begin()->size() == bs.size())
                    res.insert(bs);
            }
            return;
        }
        
        if (s[i] == '(') {
            rec(s, i + 1, bs, balance, res);
            bs.push_back(s[i]);
            rec(s, i + 1, bs, balance + 1, res);
            bs.pop_back();
        } else if (s[i] == ')') {
            rec(s, i + 1, bs, balance, res);
            if (balance) {
                bs.push_back(s[i]);
                rec(s, i + 1, bs, balance - 1, res);
                bs.pop_back();
            }
        } else {
            bs.push_back(s[i]);
            rec(s, i + 1, bs, balance, res);
            bs.pop_back();
        }
    }
    
public:
    vector<string> removeInvalidParentheses(string &s) {
        string bs;
        unordered_set<string> res;
        rec(s, 0, bs, 0, res);
        return { res.begin(), res.end() };
    }
};