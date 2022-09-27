class Solution {
    int getSum(vector<int> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
    
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &p, int k) {
        partial_sum(p.begin(), p.end(), p.begin());
        
        vector<pair<int, int>> l(p.size());
        for (int i = 0; i + k <= p.size(); i++) {
            int sum = getSum(p, i, i + k - 1);
            if (i && l[i - 1].first >= sum)
                l[i] = l[i - 1];
            else
                l[i] = { sum, i };
        }
        
        vector<pair<int, int>> r(p.size());
        for (int i = p.size() - k; i >= 0; i--) {
            int sum = getSum(p, i, i + k - 1);
            if (i + k < p.size() && r[i + 1].first > sum)
                r[i] = r[i + 1];
            else
                r[i] = { sum, i };
        }
        
        int resSum = 0;
        vector<int> res;
        
        for (int bFrom = k; bFrom + k < p.size(); bFrom++) {
            auto [aSum, aFrom] = l[bFrom - k];
            int bSum = getSum(p, bFrom, bFrom + k - 1);
            auto [cSum, cFrom] = r[bFrom + k];
            
            int curSum = aSum + bSum + cSum;
            vector<int> cur = { aFrom, bFrom, cFrom };
            
            if (resSum < curSum || resSum == curSum && res > cur) {
                resSum = curSum;
                res = cur;
            }
        }
        
        return res;
    }
};