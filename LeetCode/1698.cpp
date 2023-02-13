class Solution {
    vector<int> prefixFunction(const string &s) {
        vector<int> p(s.size());
        for (int i = 1; i < s.size(); i++) {
            int border = p[i - 1];
            while (border > 0 && s[i] != s[border])
                border = p[border - 1];
            p[i] = border + (s[i] == s[border]);
        }
        return p;
    }

public:
    int countDistinct(string &s) {
        int res = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            vector<int> p = prefixFunction(s.substr(i));
            res += i + 1 - *max_element(p.begin(), p.end());
        }
        return res;
    }
};