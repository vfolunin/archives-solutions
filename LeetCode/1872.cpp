class Solution {
public:
    int stoneGameVIII(vector<int> &p) {
        partial_sum(p.begin(), p.end(), p.begin());
        
        int res = p.back();
        for (int i = p.size() - 2; i; i--)
            res = max(res, p[i] - res);
    
        return res;
    }
};