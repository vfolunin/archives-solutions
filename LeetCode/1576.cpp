class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.size(); ) {
            if (s[i] != '?') {
                i++;
                continue;
            }
            
            int j = i;
            while (j < s.size() && s[j] == '?')
                j++;
            
            char a = 'a';
            while (0 < i && s[i - 1] == a || j < s.size() && s[j] == a)
                a++;
            
            char b = a + 1;
            while (0 < i && s[i - 1] == b || j < s.size() && s[j] == b)
                b++;
            
            while (i != j) {
                s[i] = i % 2 ? a : b;
                i++;
            }
        }
        
        return s;
    }
};