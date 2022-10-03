class Solution {
    int rec(vector<int> &a, int slotCount, int i, int mask, vector<vector<int>> &memo) {
        int &res = memo[i][mask];
        if (res != -1)
            return res;

        if (!i || !mask)
            return res = (!i && !mask ? 0 : -2);

        res = 0;
        for (int slot = 1, power = 1, m = mask; slot <= slotCount; slot++, power *= 3, m /= 3) {
            if (m % 3) {
                int prevSum = rec(a, slotCount, i - 1, mask - power, memo);
                if (prevSum != -2)
                    res = max(res, prevSum + (a[i - 1] & slot));
            }
        }
        return res;
    }

public:
    int maximumANDSum(vector<int> &a, int slotCount) {
        int maxMask = 1;
        for (int i = 0; i < slotCount; i++)
            maxMask *= 3;

        int res = 0;
        vector<vector<int>> memo(a.size() + 1, vector<int>(maxMask, -1));
        for (int mask = 0; mask < maxMask; mask++)
            res = max(res, rec(a, slotCount, a.size(), mask, memo));
        return res;
    }
};