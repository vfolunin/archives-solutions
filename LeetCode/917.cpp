class Solution {
public:
    string reverseOnlyLetters(string s) {
        for (int l = 0, r = s.size() - 1; 1; l++, r--) {
            while (l < r && !isalpha(s[l]))
                l++;
            while (l < r && !isalpha(s[r]))
                r--;
            if (l >= r)
                break;
            swap(s[l], s[r]);
        }
        return s;
    }
};