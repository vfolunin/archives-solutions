class Solution {
    string normalize(string s) {
        int shift = 'z' - s[0];
        for (char &c : s)
            c = (c - 'a' + shift) % 26 + 'a';
        return s;
    }

public:
    vector<vector<string>> groupStrings(vector<string> &a) {
        unordered_map<string, vector<string>> groups;
        for (string &s : a)
            groups[normalize(s)].push_back(s);
        
        vector<vector<string>> res;
        for (auto &[normalized, group] : groups)
            res.push_back(group);
        return res;
    }
};