class Solution {
public:
    string toHex(int n) {
        static const string DIGITS = "0123456789abcdef";
        string res;
        for (int shift = 28; shift >= 0; shift -= 4)
            if (((n >> shift) & 0xf) || !res.empty() || !shift)
                res += DIGITS[(n >> shift) & 0xf];
        return res;
    }
};