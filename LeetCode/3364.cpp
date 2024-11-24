class Solution {
public:
    int minimumSumSubarray(vector<int> &a, int minWidth, int maxWidth) {
        int res = 1e9;

        for (int l = 0; l < a.size(); l++) {
            int sum = 0;
            for (int r = l, width = 1; r < a.size(); r++, width++) {
                sum += a[r];

                if (minWidth <= width && width <= maxWidth && sum > 0)
                    res = min(res, sum);
            }
        }

        return res < 1e9 ? res : -1;
    }
};