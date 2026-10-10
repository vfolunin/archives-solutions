class Solution {
public:
    int resilientSubarray(vector<int> &a, int divisor) {
        int res = 1;
        for (int l = 0; l < a.size(); l++) {
            int sumRemainder = 0, minRemainder = divisor, maxRemainder = -1;
            for (int r = l; r < a.size(); r++) {
                sumRemainder = (sumRemainder + a[r]) % divisor;
                minRemainder = min(minRemainder, a[r] % divisor);
                maxRemainder = max(maxRemainder, a[r] % divisor);
                if (sumRemainder == minRemainder && sumRemainder == maxRemainder)
                    res = max(res, r - l + 1);
            }
        }
        return res;
    }
};