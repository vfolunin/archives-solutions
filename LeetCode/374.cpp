class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int ans = guess(m);
            if (ans == 0)
                return m;
            if (ans > 0)
                l = m + 1;
            else
                r = m - 1;
        }
        return 0;
    }
};