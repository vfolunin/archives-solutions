class Solution {
public:
    int numberOfSpecialChars(string &s) {
        int res = 0;
        for (int i = 0; i < 26; i++) {
            int l = s.rfind(i + 'a'), r = s.find(i + 'A');
            res += l != -1 && r != -1 && l < r;
        }
        return res;
    }
};