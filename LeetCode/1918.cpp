class Solution {
    int lessSumCount(vector<int> &a, int targetSum) {
        int sum = 0, res = 0;
        for (int l = 0, r = 0; r < a.size(); r++) {
            sum += a[r];
            while (sum >= targetSum) {
                sum -= a[l];
                l++;
            }
            res += r - l + 1;
        }
        return res;
    }

public:
    int kthSmallestSubarraySum(vector<int> &a, int k) {
        int l = 0, r = 2e9;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (lessSumCount(a, m) < k)
                l = m;
            else
                r = m;
        }
        return l;
    }
};