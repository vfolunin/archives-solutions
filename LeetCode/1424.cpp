class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &a) {
        map<int, vector<int>> diags;
        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < a[i].size(); j++)
                diags[i + j].push_back(a[i][j]);
        
        vector<int> res;
        for (auto &[_, diag] : diags)
            res.insert(res.end(), diag.rbegin(), diag.rend());
        return res;
    }
};