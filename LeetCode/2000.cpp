class Solution {
public:
    string reversePrefix(string s, char c) {
        reverse(s.begin(), s.begin() + s.find(c) + 1);
        return s;
    }
};