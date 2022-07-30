class Solution {
    bool isSubstring(string &a, string &b) {
        int bi = 0;
        for (int ai = 0; ai < a.size() && bi < b.size(); ai++)
            bi += a[ai] == b[bi];
        return bi == b.size();
    }
    
    string uppers(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](char c) {
            return islower(c);
        }), s.end());
        return s;
    }
    
public:
    vector<bool> camelMatch(vector<string> &queries, string &pattern) {
        vector<bool> res(queries.size());
        string patternUppers = uppers(pattern);
        for (int i = 0; i < res.size(); i++)
            res[i] = isSubstring(queries[i], pattern) && uppers(queries[i]) == patternUppers;
        return res;
    }
};