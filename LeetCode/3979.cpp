class Solution {
public:
    int maxValidPairSum(vector<int> &a, int dist) {
        int maxValue = 0, res = 0;
        for (int l = 0, r = dist; r < a.size(); l++, r++) {
            maxValue = max(maxValue, a[l]);
            res = max(res, maxValue + a[r]);
        }
        return res;
    }
};