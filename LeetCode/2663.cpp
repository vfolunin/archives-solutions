class Solution {
    string makeBeautifulString(string s, int from, char c) {       
        s[from] = c;
        for (int i = from + 1; i < s.size(); i++) {
            for (char c = 'a'; 1; c++) {
                if (c != s[i - 1] && (i < 2 || c != s[i - 2])) {
                    s[i] = c;
                    break;
                }
            }
        }        
        return s;
    }
    
public:
    string smallestBeautifulString(string &s, int letterCount) {
        for (int i = s.size() - 1; i >= 0; i--)
            for (char c = s[i] + 1; c < 'a' + letterCount; c++)
                if ((i < 1 || c != s[i - 1]) && (i < 2 || c != s[i - 2]))
                    return makeBeautifulString(s, i, c);
        return "";
    }
};