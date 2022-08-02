class Solution {
public:
    int maxAbsoluteSum(vector<int> &p) {
        partial_sum(p.begin(), p.end(), p.begin());
        
        int minP = 0, maxP = 0, res = 0;
        for (int p : p) {
            res = max(res, abs(p - minP));
            res = max(res, abs(p - maxP));
            minP = min(minP, p);
            maxP = max(maxP, p);
        }
        return res;
    }
};