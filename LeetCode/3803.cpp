class Solution {
public:
    int residuePrefixes(string &s) {
        unordered_set<char> letters;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            letters.insert(s[i]);
            res += letters.size() == (i + 1)  % 3;
        }
        return res;
    }
};