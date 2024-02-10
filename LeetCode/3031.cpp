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
    int minimumTimeToInitialState(string &s, int k) {
        vector<int> p = prefixFunction(s);
        for (int len = p.back(); len; len = p[len - 1])
            if ((s.size() - len) % k == 0)
                return (s.size() - len) / k;
        return (s.size() + k - 1) / k;
    }
};