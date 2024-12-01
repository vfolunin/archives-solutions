class Solution {
public:
    int getLargestOutlier(vector<int> &a) {
        sort(a.begin(), a.end());
        int sum = accumulate(a.begin(), a.end(), 0);

        int res = -1e9;
        for (int i = 0; i < a.size(); i++) {
            if ((sum - a[i]) % 2)
                continue;
            int j = lower_bound(a.begin(), a.end(), (sum - a[i]) / 2) - a.begin();
            if (i != j && j < a.size() && a[j] == (sum - a[i]) / 2)
                res = max(res, a[i]);
        }
        return res;
    }
};