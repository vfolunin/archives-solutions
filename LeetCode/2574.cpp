class Solution {
    int getSum(vector<int> &p, int l, int r) {
        if (l > r)
            return 0;
        return p[r] - (l ? p[l - 1] : 0);
    }
    
public:
    vector<int> leftRigthDifference(vector<int> &p) {
        partial_sum(p.begin(), p.end(), p.begin());
        
        vector<int> res(p.size());
        for (int i = 0; i < p.size(); i++)
            res[i] = abs(getSum(p, 0, i - 1) - getSum(p, i + 1, p.size() - 1));
        return res;
    }
};