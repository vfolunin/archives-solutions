class Solution {
public:
    int minSwap(vector<int> &a, vector<int> &b) {
        vector<vector<int>> res(a.size(), vector<int>(2, 1e9));
        res[0][0] = 0;
        res[0][1] = 1;
        
        for (int i = 1; i < a.size(); i++) {
            if (a[i - 1] < a[i] && b[i - 1] < b[i]) {
                res[i][0] = min(res[i][0], res[i - 1][0]);
                res[i][1] = min(res[i][1], res[i - 1][1] + 1);
            }
            if (b[i - 1] < a[i] && a[i - 1] < b[i])
                res[i][0] = min(res[i][0], res[i - 1][1]);
            if (a[i - 1] < b[i] && b[i - 1] < a[i])
                res[i][1] = min(res[i][1], res[i - 1][0] + 1);
        }
        
        return *min_element(res.back().begin(), res.back().end());
    }
};