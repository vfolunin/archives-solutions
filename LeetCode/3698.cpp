class Solution {
public:
    long long splitArray(vector<int> &a) {
        vector<int> lIncreasing(a.size(), 1);
        for (int i = 1; i < a.size(); i++)
            lIncreasing[i] = lIncreasing[i - 1] && a[i - 1] < a[i];

        vector<int> rDecreasing(a.size(), 1);
        for (int i = (int)a.size() - 2; i >= 0; i--)
            rDecreasing[i] = rDecreasing[i + 1] && a[i] > a[i + 1];
        
        long long lSum = 0, rSum = accumulate(a.begin(), a.end(), 0LL), res = 1e18;
        for (int i = 0; i + 1 < a.size(); i++) {
            lSum += a[i];
            rSum -= a[i];
            if (lIncreasing[i] && rDecreasing[i + 1])
                res = min(res, abs(lSum - rSum));
        }
        return res != 1e18 ? res : -1;
    }
};