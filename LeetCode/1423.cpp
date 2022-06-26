class Solution {
public:
    int maxScore(vector<int> &p, int k) {
        partial_sum(p.begin(), p.end(), p.begin());
        
        if (k == p.size())
            return p.back();
        
        k = p.size() - k;
        int res = p[k - 1];
        
        for (int l = 1, r = k; r < p.size(); l++, r++)
            res = min(res, p[r] - p[l - 1]);
        
        return p.back() - res;
    }
};