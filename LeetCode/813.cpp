class Solution {
    int getSum(vector<int> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
    
public:
    double largestSumOfAverages(vector<int> &p, int partLimit) {
        partial_sum(p.begin(), p.end(), p.begin());
        
        vector<vector<double>> res(p.size(), vector<double>(partLimit + 1));
        for (int i = 0; i < p.size(); i++) {
            res[i][1] = (double)getSum(p, 0, i) / (i + 1);
            
            for (int parts = 2; parts <= partLimit; parts++)
                for (int part = 1; parts - 1 + part <= i + 1; part++)
                    res[i][parts] = max(res[i][parts], res[i - part][parts - 1] +
                                        (double)getSum(p, i - part + 1, i) / part);
        }
        
        return res.back().back();
    }
};