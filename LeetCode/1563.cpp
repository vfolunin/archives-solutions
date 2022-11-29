class Solution {
    int getSum(vector<int> &p, int l, int r) {
        if (l > r)
            return 0;
        return p[r] - (l ? p[l - 1] : 0);
    }
    
    int getM(vector<int> &p, int pl, int pr) {
        int l = pl - 1, r = pr;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (getSum(p, pl, m) < getSum(p, m + 1, pr))
                l = m;
            else
                r = m;
        }
        return r;
    }
    
public:
    int stoneGameV(vector<int> &p) {
        partial_sum(p.begin(), p.end(), p.begin());
        
        vector<vector<int>> res(p.size(), vector<int>(p.size()));
        vector<vector<int>> resL(p.size(), vector<int>(p.size()));
        vector<vector<int>> resR(p.size(), vector<int>(p.size()));
        
        for (int i = 0; i < p.size(); i++)
            resL[i][i] = resR[i][i] = getSum(p, i, i);
        
        for (int len = 2; len <= p.size(); len++) {
            for (int l = 0, r = len - 1; r < p.size(); l++, r++) {
                int m = getM(p, l, r);
                
                if (getSum(p, l, m) == getSum(p, m + 1, r))
                    res[l][r] = max(resL[l][m], resR[m + 1][r]);
                else if (l == m)
                    res[l][r] = resR[l + 1][r];
                else if (m == r)
                    res[l][r] = resL[l][r - 1];
                else
                    res[l][r] = max(resL[l][m - 1], resR[m + 1][r]);
                
                resL[l][r] = max(resL[l][r - 1], getSum(p, l, r) + res[l][r]);
                resR[l][r] = max(resR[l + 1][r], getSum(p, l, r) + res[l][r]);
            }
        }
        
        return res[0][p.size() - 1];
    }
};