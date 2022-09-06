class Solution {
public:
    vector<bool> canEat(vector<int> &a, vector<vector<int>> &queries) {
        vector<pair<long long, long long>> ranges(a.size());
        long long sum = 0;
        for (int i = 0; i < a.size(); i++) {
            ranges[i] = { sum, sum + a[i] - 1 };
            sum += a[i];
        }
        
        vector<bool> res(queries.size());
        for (int i = 0; i < res.size(); i++) {
            long long index = queries[i][0], day = queries[i][1], capacity = queries[i][2];
            res[i] = ranges[index].first / capacity <= day && day <= ranges[index].second;
        }
        return res;
    }
};