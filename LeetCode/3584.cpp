class Solution {
public:
    long long maximumProduct(vector<int> &a, int size) {
        vector<long long> lMin(a.begin(), a.end()), lMax(a.begin(), a.end());
        for (int i = 1; i < a.size(); i++) {
            lMin[i] = min(lMin[i - 1], lMin[i]);
            lMax[i] = max(lMax[i - 1], lMax[i]);
        }

        long long res = -1e18;
        for (int i = size - 1; i < a.size(); i++)
            res = max({ res, a[i] * lMin[i - size + 1], a[i] * lMax[i - size + 1] });
        return res;
    }
};