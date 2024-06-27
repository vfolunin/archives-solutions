class Solution {
public:
    long long maximumTotalDamage(vector<int> &a) {
        sort(a.begin(), a.end());

        vector<long long> res(a.size());
        long long maxPredRes = 0;

        for (int l = -1, r = 0; r < a.size(); r++) {
            if (r && a[r - 1] == a[r]) {
                res[r] = res[r - 1] + a[r];
            } else {
                while (a[l + 1] + 2 < a[r]) {
                    l++;
                    maxPredRes = max(maxPredRes, res[l]);
                }
                res[r] = maxPredRes + a[r];
            }
        }

        return *max_element(res.begin(), res.end());
    }
};