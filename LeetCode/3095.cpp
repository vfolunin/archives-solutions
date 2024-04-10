class Solution {
public:
    int minimumSubarrayLength(vector<int> &a, int threshold) {
        int res = 1e9;
        for (int l = 0; l < a.size(); l++) {
            int orSum = 0;
            for (int r = l; r < a.size(); r++) {
                orSum |= a[r];
                if (orSum >= threshold) {
                    res = min(res, r - l + 1);
                    break;
                }
            }
        }
        return res != 1e9 ? res : -1;
    }
};