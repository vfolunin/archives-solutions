class Solution {
public:
    vector<int> resultsArray(vector<vector<int>> &queries, int k) {
        multiset<int> values;
        vector<int> res(queries.size(), -1);
        
        for (int i = 0; i < queries.size(); i++) {
            values.insert(abs(queries[i][0]) + abs(queries[i][1]));
            if (values.size() > k)
                values.erase(prev(values.end()));
                
            if (values.size() == k)
                res[i] = *prev(values.end());
        }

        return res;
    }
};