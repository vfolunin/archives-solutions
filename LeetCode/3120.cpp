class Solution {
public:
    int numberOfSpecialChars(string &s) {
        int res = 0;
        for (int i = 0; i < 26; i++)
            res += s.find(i + 'a') != -1 && s.find(i + 'A') != -1;
        return res;
    }
};