class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &a, vector<vector<int>> &b) {
        map<int, int> count;
        for (vector<int> &item : a)
            count[item[0]] += item[1];
        for (vector<int> &item : b)
            count[item[0]] += item[1];
            
        vector<vector<int>> res;
        for (auto &[value, count] : count)
            res.push_back({ value, count });
        return res;
    }
};