class Solution {
    vector<string> getParts(string &s) {
        vector<string> parts;
        stringstream ss(s);
        char c;

        while (ss >> c) {
            if (c == '{') {
                parts.emplace_back();
                
                while (1) {
                    ss >> c;
                    if (isalpha(c))
                        parts.back() += c;
                    else if (c == '}')
                        break;
                }

                sort(parts.back().begin(), parts.back().end());
            } else {
                parts.push_back(string(1, c));
            }
        }

        return parts;
    }

    void rec(vector<string> &parts, int i, string &s, vector<string> &res) {
        if (i == parts.size()) {
            res.push_back(s);
            return;
        }

        for (char c : parts[i]) {
            s.push_back(c);
            rec(parts, i + 1, s, res);
            s.pop_back();
        }
    }

public:
    vector<string> expand(string &s) {
        vector<string> parts = getParts(s);
        s.clear();
        vector<string> res;
        rec(parts, 0, s, res);
        return res;
    }
};