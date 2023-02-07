class Solution {
public:
    string encode(int n) {
        int len = 0;
        while (n >= (1 << len)) {
            n -= 1 << len;
            len++;
        }

        string res;
        for (int i = 0; i < len; i++) {
            res += n % 2 + '0';
            n /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};