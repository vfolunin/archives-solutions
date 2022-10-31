class Solution {
public:
    string lastSubstring(string &s) {
        int fromA = 0, fromB = 1, size = 1;
        
        while (fromB + size <= s.size()) {
            if (s[fromA + size - 1] == s[fromB + size - 1]) {
                size++;
            } else {
                if (s[fromA + size - 1] > s[fromB + size - 1]) {
                    fromB += size;
                } else {
                    fromA = max(fromA + size, fromB);
                    fromB = fromA + 1;
                }
                size = 1;
            }
        }
        
        return s.substr(fromA);
    }
};