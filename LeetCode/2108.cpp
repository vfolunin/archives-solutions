class Solution {
    bool isPalindrome(string &s) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--)
            if (s[l] != s[r])
                return 0;
        return 1;
    }
    
public:
    string firstPalindrome(vector<string> &words) {
        for (string &word : words)
            if (isPalindrome(word))
                return word;
        return "";
    }
};