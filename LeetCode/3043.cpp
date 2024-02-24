class Solution {
public:
    int longestCommonPrefix(vector<int> &a, vector<int> &b) {
        unordered_set<string> prefixes;
        for (int value : a) {
            string s = to_string(value);
            for (int len = 1; len <= s.size(); len++)
                prefixes.insert(s.substr(0, len));
        }

        int res = 0;
        for (int value : b) {
            string s = to_string(value);
            for (int len = 1; len <= s.size(); len++)
                if (prefixes.count(s.substr(0, len)))
                    res = max(res, len);
        }
        return res;
    }
};