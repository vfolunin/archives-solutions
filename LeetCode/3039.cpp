class Solution {
public:
    string lastNonEmptyString(string &s) {
        vector<int> count(26);
        int maxCount = 0;
        for (char &c : s)
            maxCount = max(maxCount, ++count[c - 'a']);
        
        string res;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (count[s[i] - 'a'] == maxCount) {
                res += s[i];
                count[s[i] - 'a'] = 0;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};