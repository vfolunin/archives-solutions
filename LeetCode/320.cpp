class Solution {
    void rec(string &s, int i, bool canReplace, string abbr, vector<string> &res) {
        if (i == s.size()) {
            res.push_back(abbr);
            return;
        }

        rec(s, i + 1, 1, abbr + s[i], res);

        if (canReplace)
            for (int count = 1; i + count <= s.size(); count++)
                rec(s, i + count, 0, abbr + to_string(count), res);
    }

public:
    vector<string> generateAbbreviations(string &s) {
        vector<string> res;
        rec(s, 0, 1, "", res);
        return res;
    }
};