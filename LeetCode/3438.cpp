class Solution {
public:
    string findValidPair(string &s) {
        vector<int> count(10);
        for (char c : s)
            count[c - '0']++;
        
        for (int i = 0; i + 1 < s.size(); i++)
            if (s[i] != s[i + 1] &&
                count[s[i] - '0'] == s[i] - '0' &&
                count[s[i + 1] - '0'] == s[i + 1] - '0')
                return s.substr(i, 2);
                
        return "";
    }
};