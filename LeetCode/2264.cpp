class Solution {
public:
    string largestGoodInteger(string s) {
        vector<int> seen(10);
        for (int i = 0; i + 2 < s.size(); i++)
            if (s[i] == s[i + 1] && s[i] == s[i + 2])
                seen[s[i] - '0'] = 1;
        
        for (int i = 9; i >= 0; i--)
            if (seen[i])
                return string(3, '0' + i);
        return "";
    }
};