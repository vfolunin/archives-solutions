class Solution {
public:
    string maximumBinaryString(string &s) {
        int i = 0;
        while (i < s.size() && s[i] == '1')
            i++;
        
        if (i < s.size()) {
            sort(s.begin() + i, s.end());
            fill(s.begin() + i, s.begin() + s.rfind('0'), '1');
        }
        
        return s;
    }
};