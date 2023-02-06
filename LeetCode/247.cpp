class Solution {
    void rec(int i, string &s, vector<string> &res) {
        if (i == s.size()) {
            res.push_back(s);
            return;
        }

        if (s.size() % 2 && i > s.size() / 2 || s.size() % 2 == 0 && i >= s.size() / 2) {
            static const string REVERSED = "01----9-86";
            s[i] = REVERSED[s[s.size() - 1 - i] - '0'];
            rec(i + 1, s, res);
            return;
        }

        if (s.size() % 2 && i == s.size() / 2) {
            for (char c : { '0', '1', '8' }) {
                s[i] = c;
                rec(i + 1, s, res);
            }
            return;
        }

        for (char c : { '0', '1', '6', '8', '9' }) {
            if (!i && c == '0')
                continue;
            s[i] = c;
            rec(i + 1, s, res);
        }
    }

public:
    vector<string> findStrobogrammatic(int size) {
        string s(size, ' ');
        vector<string> res;
        rec(0, s, res);
        return res;
    }
};