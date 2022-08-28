class Solution {
public:
    vector<int> answerQueries(vector<int> &a, vector<int> &queries) {
        sort(a.begin(), a.end());
        partial_sum(a.begin(), a.end(), a.begin());
        
        vector<int> res(queries.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = upper_bound(a.begin(), a.end(), queries[i]) - a.begin();
        return res;
    }
};