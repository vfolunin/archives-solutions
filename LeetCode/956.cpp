class Solution {   
public:
    int tallestBillboard(vector<int> &a) {
        vector<vector<int>> res(a.size() + 1, vector<int>(1e4 + 1, -1));
        res[0][5000] = 0;
        
        for (int i = 0; i < a.size(); i++) {
            for (int sum = 0; sum < res[i].size(); sum++) {
                if (res[i][sum] == -1)
                    continue;
                
                res[i + 1][sum] = max(res[i + 1][sum], res[i][sum]);
                if (0 <= sum - a[i])
                    res[i + 1][sum - a[i]] = max(res[i + 1][sum - a[i]], res[i][sum]);
                if (sum + a[i] < res[i].size())
                    res[i + 1][sum + a[i]] = max(res[i + 1][sum + a[i]], res[i][sum] + a[i]);
            }
        }
        
        return max(0, res[a.size()][5000]);
    }
};