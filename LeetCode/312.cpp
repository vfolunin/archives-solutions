class Solution {
public:
    int maxCoins(vector<int> &a) {
        a.insert(a.begin(), 1);
        a.push_back(1);
        
        vector<vector<int>> res(a.size(), vector<int>(a.size()));
        
        for (int i = 0; i < a.size(); i++)
            res[i][i] = a[i];
        
        for (int len = 2; len <= a.size(); len++)
            for (int l = 0, r = len - 1; r < a.size(); l++, r++)
                for (int m = l + 1; m < r; m++)
                    res[l][r] = max(res[l][r], res[l][m] + a[l] * a[m] * a[r] + res[m][r]);
        
        return res[0][a.size() - 1];
    }
};