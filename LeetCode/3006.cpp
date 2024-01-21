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

    vector<int> find(string &text, string &pattern) {
        vector<int> p = prefixFunction(pattern + "#" + text);
        vector<int> res;
        for (int i = 0; i < p.size(); i++)
            if (p[i] == pattern.size())
                res.push_back(i - 2 * pattern.size());
        return res;
    }

public:
    vector<int> beautifulIndices(string &s, string &sa, string &sb, int limit) {
        vector<int> a = find(s, sa);
        vector<int> b = find(s, sb);

        vector<int> res;
        for (int ai = 0, bi = 0; ai < a.size() && bi < b.size(); ai++) {
            while (bi < b.size() && b[bi] <= a[ai] + limit && abs(a[ai] - b[bi]) > limit)
                bi++;
            if (bi < b.size() && abs(a[ai] - b[bi]) <= limit)
                res.push_back(a[ai]);
        }
        return res;
    }
};