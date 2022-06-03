class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < s.size(); i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }
        
        int res = -1;
        for (int i = 0; i < 26; i++)
            res = max(res, last[i] - first[i] - 1);
        return res;
    }
};