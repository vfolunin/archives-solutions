class Solution {
public:
    string maximumOddBinaryNumber(string &s) {
        sort(s.rbegin(), s.rend());
        swap(s[s.rfind('1')], s.back());
        return s;
    }
};