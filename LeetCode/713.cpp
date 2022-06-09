class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &a, int k) {
        int res = 0;
        
        for (int l = 0, r = 0, p = 1; r < a.size(); r++) {
            p *= a[r];
            while (l <= r && p >= k) {
                p /= a[l];
                l++;
            }
            res += r - l + 1;
        }
        
        return res;
    }
};