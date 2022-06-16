class Solution {
    void rec(int n, int step, int open, string &s, vector<string> &res) {
        if (step == 2 * n) {
            res.push_back(s);
            return;
        }
        if (step + open < 2 * n) {
            s.push_back('(');
            rec(n, step + 1, open + 1, s, res);
            s.pop_back();
        }
        if (open) {
            s.push_back(')');
            rec(n, step + 1, open - 1, s, res);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        rec(n, 0, 0, s, res);
        return res;
    }
};