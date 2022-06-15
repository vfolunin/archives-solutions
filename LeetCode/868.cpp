class Solution {
public:
    int binaryGap(int n) {
        int last = -1, res = 0;
        for (int i = 0; n; n /= 2, i++) {
            if (n % 2) {
                if (last != -1 && i - last > res)
                    res = i - last;
                last = i;
            }
        }
        return res;
    }
};