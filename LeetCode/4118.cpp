class Solution {
public:
    int minOperations(vector<int> &a) {
        vector<vector<int>> lOps(a.size(), vector<int>(2001, 1e9));
        for (int value = 1; value < lOps[0].size(); value++)
            lOps[0][value] = min(lOps[0][value - 1], abs(a[0] - value));
        for (int i = 1; i < a.size(); i++)
            for (int value = 1; value < lOps[i].size(); value++)
                lOps[i][value] = min(lOps[i][value - 1], lOps[i - 1][value - 1] + abs(a[i] - value));
        
        vector<vector<int>> rOps(a.size(), vector<int>(2001, 1e9));
        for (int value = 1; value < rOps[0].size(); value++)
            rOps[a.size() - 1][value] = min(rOps[a.size() - 1][value - 1], abs(a[a.size() - 1] - value));
        for (int i = (int)a.size() - 2; i >= 0; i--)
            for (int value = 1; value < rOps[i].size(); value++)
                rOps[i][value] = min(rOps[i][value - 1], abs(a[i] - value) + rOps[i + 1][value - 1]);

        int res = 1e9;
        for (int i = 1; i + 1 < a.size(); i++)
            for (int value = 1; value < lOps[i].size(); value++)
                res = min(res, lOps[i - 1][value - 1] + abs(a[i] - value) + rOps[i + 1][value - 1]);
        return res != 1e9 ? res : -1;
    }
};