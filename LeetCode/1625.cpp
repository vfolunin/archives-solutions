class Solution {
    void rec(string &s, int a, int b, unordered_set<string> &seen, string &res) {
        if (seen.count(s))
            return;
        seen.insert(s);
        
        if (res.empty() || res > s)
            res = s;
        
        string t = s;
        for (int i = 1; i < s.size(); i += 2)
            t[i] = (t[i] - '0' + a) % 10 + '0';
        rec(t, a, b, seen, res);
        
        rotate(s.begin(), s.begin() + b, s.end());
        rec(s, a, b, seen, res);
    }
    
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> seen;
        string res;
        rec(s, a, b, seen, res);
        return res;
    }
};