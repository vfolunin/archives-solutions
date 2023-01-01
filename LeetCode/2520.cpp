class Solution {
public:
    int countDigits(int n) {
        int res = 0;
        for (char c : to_string(n))
            res += c != '0' && n % (c - '0') == 0;
        return res;
    }
};