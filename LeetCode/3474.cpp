class Solution {
    bool equals(string &res, string &s, int i) {
        for (int j = 0; j < s.size(); j++)
            if (res[i + j] != s[j])
                return 0;
        return 1;
    }

public:
    string generateString(string &equal, string &s) {
        string res(equal.size() + s.size() - 1, 'a');
        vector<int> fixed(equal.size() + s.size() - 1);

        for (int i = 0; i < equal.size(); i++) {
            if (equal[i] == 'T') {
                for (int j = 0; j < s.size(); j++) {
                    if (!fixed[i + j]) {
                        res[i + j] = s[j];
                        fixed[i + j] = 1;
                    } else if (res[i + j] != s[j]) {
                        return "";
                    }
                }
            }
        }

        for (int i = 0; i < equal.size(); i++) {
            if (equal[i] == 'F' && equals(res, s, i)) {
                bool found = 0;
                for (int j = (int)s.size() - 1; j >= 0; j--) {
                    if (!fixed[i + j]) {
                        res[i + j] = 'b';
                        fixed[i + j] = 1;
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    return "";
            }
        }
        
        return res;
    }
};