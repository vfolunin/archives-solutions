class Solution {
public:
    int minSubArrayLen(int targetSum, vector<int> &a) {
        int sum = 0, res = a.size() + 1;
        for (int l = 0, r = 0; r < a.size(); r++) {
            sum += a[r];
            while (sum >= targetSum) {
                res = min(res, r - l + 1);
                sum -= a[l];
                l++;
            }
        }
        return res != a.size() + 1 ? res : 0;
    }
};