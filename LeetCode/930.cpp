class Solution {
public:
    int numSubarraysWithSum(vector<int> &p, int target) {
        partial_sum(p.begin(), p.end(), p.begin());
        
        int res = 0;
        for (int i = 0; i < p.size(); i++) {
            auto [l, r] = equal_range(p.begin() + i, p.end(), (i ? p[i - 1] : 0) + target);
            res += r - l;
        }
        return res;
    }
};