class Solution {
public:
    string smallestPalindrome(string &s) {
        sort(s.begin(), s.begin() + s.size() / 2);
        sort(s.rbegin(), s.rbegin() + s.size() / 2);
        return s;
    }
};