class Solution {
public:
    int findSubstringInWraproundString(string &s) {
        vector<int> count(s.size(), 1);
        for (int i = 1; i < s.size(); i++)
            if ((s[i - 1] - 'a' + 1) % 26 + 'a' == s[i])
                count[i] = count[i - 1] + 1;
        
        vector<int> countTo(26);
        for (int i = 0; i < s.size(); i++)
            countTo[s[i] - 'a'] = max(countTo[s[i] - 'a'], count[i]);
        
        int res = 0;
        for (int value : countTo)
            res += value;
        return res;
    }
};