class Solution {
public:
    string largestOddNumber(string s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] % 2 == 0)
            i--;
        return i >= 0 ? s.substr(0, i + 1) : "";
    }
};