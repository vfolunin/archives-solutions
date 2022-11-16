class Solution {
    bool isSubsequence(string &a, string &b, int rep) {
        if (b.empty())
            return 1;
        
        int bi = 0;
        for (int ai = 0; ai < a.size(); ai++)
            if (a[ai] == b[bi % b.size()])
                bi++;
        return bi >= b.size() * rep;
    }
    
    void rec(string &a, string &b, int rep, vector<int> &count, string &res) {
        if (!isSubsequence(a, b, rep))
            return;
        
        if (res.size() < b.size())
            res = b;
        
        for (char c = 'z'; c >= 'a'; c--) {
            if (count[c - 'a'] >= rep) {
                count[c - 'a'] -= rep;
                b.push_back(c);
                rec(a, b, rep, count, res);
                count[c - 'a'] += rep;
                b.pop_back();
            }
        }
    }
    
public:
    string longestSubsequenceRepeatedK(string &s, int rep) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        
        string b, res;
        rec(s, b, rep, count, res);
        return res;
    }
};