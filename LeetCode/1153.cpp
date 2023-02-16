class Solution {
public:
    bool canConvert(string &a, string &b) {
        string to(26, ' ');
        for (int i = 0; i < a.size(); i++) {
            if (to[a[i] - 'a'] != ' ' && to[a[i] - 'a'] != b[i])
                return 0;
            to[a[i] - 'a'] = b[i];
        }

        return a == b || unordered_set<char>(b.begin(), b.end()).size() < 26;
    }
};