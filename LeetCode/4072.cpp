class Solution {
public:
    long long maxAlternatingSum(vector<int> &a) {
        vector<long long> lMax0(a.size(), -1e18);
        vector<long long> lMax1(a.begin(), a.end());
        for (int i = 1; i < a.size(); i++) {
            lMax0[i] = max(lMax0[i], lMax1[i - 1] - a[i]);
            lMax1[i] = max(lMax1[i], max(lMax0[i - 1], 0LL) + a[i]);
        }

        vector<long long> rMin(a.size());
        vector<long long> rMax(a.size());
        for (int i = a.size() - 1; i >= 0; i--) {
            rMin[i] = min(a[i], 0);
            rMax[i] = max(a[i], 0);
            if (i + 1 < a.size()) {
                rMin[i] = min(rMin[i], a[i] - rMax[i + 1]);
                rMax[i] = max(rMax[i], a[i] - rMin[i + 1]);
            }
        }

        long long res = -1e18;
        for (int i = 0; i < a.size(); i++)
            res = max({ res, lMax0[i], lMax1[i] });
        for (int i = 1; i + 1 < a.size(); i++)
            res = max({ res, lMax0[i - 1] + rMax[i + 1], lMax1[i - 1] - rMin[i + 1] });
        return res;
    }
};