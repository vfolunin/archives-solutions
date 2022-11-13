class Solution {
public:
    int subarrayLCM(vector<int> &a, int k) {
        int res = 0;
        for (int l = 0; l < a.size(); l++) {
            long long value = a[l];
            for (int r = l; r < a.size() && value <= k; r++) {
                value = lcm(value, a[r]);
                res += value == k;
            }
        }
        return res;
    }
};