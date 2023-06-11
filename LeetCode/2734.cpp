class Solution {
public:
    string smallestString(string &s) {
        int i = 0;
        while (i < s.size() && s[i] == 'a')
            i++;
        
        if (i == s.size()) {
            s.back() = 'z';
            return s;
        }

        while (i < s.size() && s[i] != 'a') {
            s[i]--;
            i++;
        }
        return s;
    }
};