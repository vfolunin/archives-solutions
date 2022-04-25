class Solution {
    int getSum(vector<int> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
    
public:
    int sumOddLengthSubarrays(vector<int> &a) {
        vector<int> p(a.size());
        partial_sum(a.begin(), a.end(), p.begin());
        
        int res = 0;
        for (int len = 1; len <= a.size(); len += 2)
            for (int l = 0, r = len - 1; r < a.size(); l++, r++)
                res += getSum(p, l, r);
        return res;
    }
};