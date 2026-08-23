class Solution {
public:
    bool isPalindromic(string &s) {
        string bin;
        for (char c : s)
            for (int bit = 7; bit >= 0; bit--)
                bin += (c >> bit) & 1;
        return bin == string(bin.rbegin(), bin.rend());
    }
};