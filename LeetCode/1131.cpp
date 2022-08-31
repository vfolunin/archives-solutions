class Solution {
    int getRange(vector<int> &a) {
        auto [minIt, maxIt] = minmax_element(a.begin(), a.end());
        return *maxIt - *minIt;
    }
    
public:
    int maxAbsValExpr(vector<int> &a, vector<int> &b) {
        vector<vector<int>> v(4, vector<int>(a.size()));
        for (int i = 0; i < a.size(); i++) {
            v[0][i] = a[i] + b[i] + i;
            v[1][i] = a[i] + b[i] - i;
            v[2][i] = a[i] - b[i] + i;
            v[3][i] = a[i] - b[i] - i;
        }
        
        int res = 0;
        for (vector<int> &v : v)
            res = max(res, getRange(v));
        return res;
    }
};