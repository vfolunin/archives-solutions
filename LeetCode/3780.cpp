class Solution {
public:
    int maximumSum(vector<int> &a) {
        vector<vector<int>> values(3);
        for (int &value : a)
            values[value % 3].push_back(value);
        
        for (vector<int> &values : values)
            sort(values.rbegin(), values.rend());
        
        int res = 0;
        if (values[0].size() >= 3)
            res = max(res, values[0][0] + values[0][1] + values[0][2]);
        if (values[0].size() >= 1 && values[1].size() >= 1 && values[2].size() >= 1)
            res = max(res, values[0][0] + values[1][0] + values[2][0]);
        if (values[1].size() >= 3)
            res = max(res, values[1][0] + values[1][1] + values[1][2]);
        if (values[2].size() >= 3)
            res = max(res, values[2][0] + values[2][1] + values[2][2]);
        return res;
    }
};