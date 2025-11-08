class Solution {
    int getSum(vector<int> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }

public:
    int countMajoritySubarrays(vector<int> &a, int target) {
        vector<int> p(a.size());
        for (int i = 0; i < p.size(); i++)
            p[i] = (a[i] == target) + (i ? p[i - 1] : 0);
        
        int res = 0;
        for (int l = 0; l < a.size(); l++)
            for (int r = l; r < a.size(); r++)
                res += getSum(p, l, r) * 2 > r - l + 1;
        return res;
    }
};