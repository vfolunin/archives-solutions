class Solution {
public:
    int maxAscendingSum(vector<int> &a) {
        int cur = a[0], res = a[0];
        for (int i = 1; i < a.size(); i++) {
            if (a[i - 1] < a[i])
                cur += a[i];
            else
                cur = a[i];
            res = max(res, cur);
        }
        return res;
    }
};