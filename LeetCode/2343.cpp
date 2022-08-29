class Solution {    
public:
    vector<int> smallestTrimmedNumbers(vector<string> &a, vector<vector<int>> &queries) {
        vector<vector<int>> sortSteps(1, vector<int>(a.size()));
        iota(sortSteps[0].begin(), sortSteps[0].end(), 0);
        
        for (int i = a[0].size() - 1; i >= 0; i--) {
            if (i < a[0].size() - 1)
                sortSteps.push_back(sortSteps.back());
            
            stable_sort(sortSteps.back().begin(), sortSteps.back().end(), [&](int lhs, int rhs) {
                return a[lhs][i] < a[rhs][i];
            });
        }
        
        vector<int> res(queries.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = sortSteps[queries[i][1] - 1][queries[i][0] - 1];
        return res;
    }
};