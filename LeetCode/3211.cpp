class Solution {
    void rec(string &s, int size, vector<string> &res) {
        if (s.size() == size) {
            res.push_back(s);
            return;
        }
        if (s.empty() || s.back() != '0') {
            s.push_back('0');
            rec(s, size, res);
            s.pop_back();
        }
        s.push_back('1');
        rec(s, size, res);
        s.pop_back();
    }

public:
    vector<string> validStrings(int size) {
        string s;
        vector<string> res;
        rec(s, size, res);
        return res;
    }
};